#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n,need,want;
int c[MAXN];
int like[MAXN];

vector<int> opt[4];

ll solve() {
	ll ret=LLONG_MAX;
	ll cur=0; int ata=0,atb=0,likea=0,likeb=0,cnt=0; priority_queue<int> avail,have;
	int mnboth=max(0,max(want-SZ(opt[1]),want-SZ(opt[2])));
	int mxboth=min(want,SZ(opt[3]));
	if(mnboth>mxboth) return -1;
	REP(i,mnboth) cur+=opt[3][i],++likea,++likeb,++cnt; FORSZ(i,mxboth,opt[3]) avail.push(-opt[3][i]);
	while(likea<want&&ata<SZ(opt[1])) cur+=opt[1][ata++],++likea,++cnt; FORSZ(i,ata,opt[1]) avail.push(-opt[1][i]);
	while(likeb<want&&atb<SZ(opt[2])) cur+=opt[2][atb++],++likeb,++cnt; FORSZ(i,atb,opt[2]) avail.push(-opt[2][i]); 
	REPSZ(i,opt[0]) avail.push(-opt[0][i]);
	while(cnt<need&&!avail.empty()) { cur-=avail.top(),have.push(-avail.top()),++cnt; avail.pop(); }
	FORE(atboth,mnboth,mxboth) {
		//printf("atboth=%d ata=%d atb=%d likea=%d likeb=%d cnt=%d -> %lld\n",atboth,ata,atb,likea,likeb,cnt,cur);
		if(likea>=want&&likeb>=want&&cnt==need) ret=min(ret,cur);
		if(atboth<mxboth) {
			cur+=opt[3][atboth],++likea,++likeb,++cnt;
			if(likea>want&&ata>0) cur-=opt[1][--ata],--likea,--cnt,avail.push(-opt[1][ata]);
			if(likeb>want&&atb>0) cur-=opt[2][--atb],--likeb,--cnt,avail.push(-opt[2][atb]);
			while(cnt>need&&!have.empty()) { cur-=have.top(),avail.push(-have.top()),--cnt; have.pop(); }
			while(cnt<need&&!avail.empty()) { cur-=avail.top(),have.push(-avail.top()),++cnt; avail.pop(); }
			while(!avail.empty()&&!have.empty()&&-avail.top()<have.top()) { int c=-avail.top(),d=have.top(); avail.pop(),have.pop(); cur+=c-d; avail.push(-d),have.push(c); }
		}
	}
	return ret==LLONG_MAX?-1:ret;
}

void run() {
	scanf("%d%d%d",&n,&need,&want);
	REP(i,n) scanf("%d",&c[i]),like[i]=0;
	{ int na; scanf("%d",&na); REP(i,na) { int x; scanf("%d",&x); --x; like[x]|=1; } }
	{ int nb; scanf("%d",&nb); REP(i,nb) { int x; scanf("%d",&x); --x; like[x]|=2; } }
	REP(i,4) opt[i].clear(); REP(i,n) opt[like[i]].PB(c[i]); REP(i,4) sort(opt[i].begin(),opt[i].end());
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}