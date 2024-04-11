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

int n;
int a[MAXN];
bool mycmp(const int &p,const int &q) { if(a[p]!=a[q]) return a[p]<a[q]; return p<q; }

int fst[3],prv[MAXN],nxt[MAXN];
int order[MAXN];
int at[3];


int ret[MAXN],nret;
bool create() {
	nret=0; int want=0;
	while(nret<n) {
		int x=want%3;
		//printf("want=%d -> at[%d]=%d\n",want,x,at[x]);
		if(at[x]==-1) break;
		if(a[at[x]]>want) return false;
		while(a[at[x]]<want&&nxt[at[x]]!=-1&&a[nxt[at[x]]]<=want) at[x]=nxt[at[x]];
		ret[nret++]=at[x]+1; want=a[at[x]]+1;
		if(prv[at[x]]!=-1) nxt[prv[at[x]]]=nxt[at[x]]; else fst[x]=nxt[at[x]];
		if(nxt[at[x]]!=-1) prv[nxt[at[x]]]=prv[at[x]];
		int natx=nxt[at[x]]!=-1?nxt[at[x]]:prv[at[x]];
		nxt[at[x]]=prv[at[x]]=-1; at[x]=natx;
	}
	return nret>=n;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) order[i]=i; sort(order,order+n,mycmp);
	REP(i,3) fst[i]=-1;
	for(int i=n-1;i>=0;--i) {
		int idx=order[i],x=a[idx]%3;
		prv[idx]=-1; nxt[idx]=fst[x]; fst[x]=idx; if(nxt[idx]!=-1) prv[nxt[idx]]=idx;
	}
	REP(i,3) at[i]=fst[i];

	if(!create()) { printf("Impossible\n"); return; }
	printf("Possible\n"); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}