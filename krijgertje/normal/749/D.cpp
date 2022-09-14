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
typedef struct P { int id,mx; } P;
bool operator<(const P &a,const P &b) { return a.mx>b.mx; }

int n,nq;
int who[MAXN],val[MAXN];
int nskip,skip[MAXN];
int mark[MAXN];

int cnt[MAXN],off[MAXN+1],sval[MAXN];
P p[MAXN]; int np;

void precalc() {
	REP(i,n) cnt[i]=0;
	REP(i,n) ++cnt[who[i]];
	off[0]=0; REP(i,n) off[i+1]=off[i]+cnt[i];
	REP(i,n) sval[off[who[i]]++]=val[i];
	REP(i,n) off[i]-=cnt[i];
	REP(i,n) sort(sval+off[i],sval+off[i+1]);
	np=0; REP(i,n) if(off[i]<off[i+1]) p[np].id=i,p[np].mx=sval[off[i+1]-1],++np;
	sort(p,p+np);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&who[i],&val[i]),--who[i];
	precalc();
	scanf("%d",&nq); memset(mark,-1,sizeof(mark));
	REP(i,nq) {
		scanf("%d",&nskip); REP(j,nskip) scanf("%d",&skip[j]),--skip[j];
		REP(j,nskip) mark[skip[j]]=i;
		int a=0; while(a<np&&mark[p[a].id]==i) ++a;
		if(a>=np) { printf("0 0\n"); continue; }
		int b=a+1; while(b<np&&mark[p[b].id]==i) ++b;
		if(b>=np) { printf("%d %d\n",p[a].id+1,sval[off[p[a].id]]); continue; }
		int l=off[p[a].id]-1,r=off[p[a].id+1]-1;
		while(l+1<r) {
			int m=l+(r-l)/2;
			if(sval[m]>p[b].mx) r=m; else l=m;
		}
		printf("%d %d\n",p[a].id+1,sval[r]);
	}
}

int main() {
	run();
	return 0;
}