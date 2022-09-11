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
const int MAXS=4*MAXN;
const int MAXA=26+26+10;

int sval[MAXS];
void spull(int x) { sval[x]=sval[2*x+1]+sval[2*x+2]; }
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=1;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=0;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*x+1,l,m,IDX);
		if(IDX>=m+1) smod(2*x+2,m+1,r,IDX);
		spull(x);
	}
}
int sget(int x,int l,int r,int POS) {
	assert(POS<sval[x]);
	if(l==r) {
		assert(sval[x]==1&&POS==0);
		return l;
	} else {
		int m=l+(r-l)/2;
		if(POS<sval[2*x+1]) return sget(2*x+1,l,m,POS); else POS-=sval[2*x+1];
		if(POS<sval[2*x+2]) return sget(2*x+2,m+1,r,POS); else POS-=sval[2*x+2];
		assert(false); return -1;
	}
}

int n,nq;
char s[MAXN+1];

int mp[256]; int na;

set<int> pos[MAXA];


void run() {
	scanf("%d%d",&n,&nq); scanf("%s",s);
	sinit(0,0,n-1);
	memset(mp,-1,sizeof(mp));
	REP(i,10) { char c='0'+i; mp[c]=na++; }
	REP(i,26) { char c='A'+i; mp[c]=na++; }
	REP(i,26) { char c='a'+i; mp[c]=na++; }
	REP(i,n) pos[mp[s[i]]].insert(i);
	int len=n;
	REP(qi,nq) {
		int l,r; char c; scanf("%d%d %c",&l,&r,&c); --l,--r;
		int orgl=sget(0,0,n-1,l),orgr=sget(0,0,n-1,r),x=mp[c];
		auto it=lower_bound(pos[x].begin(),pos[x].end(),orgl);
		while(it!=pos[x].end()&&*it<=orgr) {
			--len;
			smod(0,0,n-1,*it);
			pos[x].erase(it++);
		}
	}
	REP(i,len) { int oi=sget(0,0,n-1,i); printf("%c",s[oi]); } puts("");
}

int main() {
	run();
	return 0;
}