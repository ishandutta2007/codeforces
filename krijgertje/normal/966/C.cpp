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

const int MAXN=100000;
const int MAXBIT=60;

int n;
ll b[MAXN];

vector<ll> bymsb[MAXBIT+1];

ll ret[MAXN]; int nret;
ll tmp[MAXN]; int ntmp;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&b[i]);

	REP(i,n) { int bit=MAXBIT; while((b[i]&(1LL<<bit))==0) --bit; bymsb[bit].PB(b[i]); }
	nret=0;
	for(int i=MAXBIT;i>=0;--i) {
		int at=0; ll cur=0; ntmp=0;
		REPSZ(j,bymsb[i]) {
			ll now=bymsb[i][j];
			while(at<nret&&(cur^now)<=cur) { cur^=ret[at]; tmp[ntmp++]=ret[at]; ++at; }
			if((cur^now)<=cur) { printf("No\n"); return; }
			cur^=now; tmp[ntmp++]=now;
		}
		while(at<nret) tmp[ntmp++]=ret[at++];
		nret=ntmp; REP(j,nret) ret[j]=tmp[j];
	}
	printf("Yes\n");
	REP(i,nret) { if(i!=0) printf(" "); printf("%lld",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}