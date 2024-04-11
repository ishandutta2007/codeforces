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

typedef struct P { ll x,y; P() {} P(ll x,ll y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }

int side(const P &a,const P &b,const P &c) {
	ll res=(b-a)^(c-a);
	return res<0?-1:res>0?+1:0;
}

int n;
P p[100000];
int h[100000],nh;
int d[100000];
int up[17][100000];

void run() {
	cin>>n;
	REP(i,n) cin>>p[i].x>>p[i].y;

	nh=0;
	for(int i=n-1;i>=0;--i) {
		while(nh>=2&&side(p[i],p[h[nh-1]],p[h[nh-2]])>0) --nh;
		up[0][i]=nh==0?i:h[nh-1];
		d[i]=nh==0?0:d[h[nh-1]]+1;
		h[nh++]=i;
//		printf("%d->%d [%d]\n",i,up[0][i],d[i]);
//		REP(j,nh) printf("(%lld,%lld)",p[h[j]].x,p[h[j]].y); puts("");
	}
	REP(k,16) REP(i,n) up[k+1][i]=up[k][up[k][i]];
//	REP(i,n) { REP(k,17) printf("%d ",up[k][i]); puts(""); }

	int nq; scanf("%d",&nq);
	REP(q,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(d[a]<d[b]) swap(a,b);
		for(int k=16;k>=0;--k) if(d[up[k][a]]>=d[b]) a=up[k][a];
		for(int k=16;k>=0;--k) if(up[k][a]!=up[k][b]) a=up[k][a],b=up[k][b];
		int lca=a==b?a:up[0][a];
		if(q!=0) printf(" "); printf("%d",lca+1);
	}
	puts("");
	
}

int main() {
	run();
	return 0;
}