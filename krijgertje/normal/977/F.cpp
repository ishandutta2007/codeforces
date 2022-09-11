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

int mxlen[MAXN]; // mxlen[i] = maximum length when ending at i
int prv[MAXN]; // prv[i] = previous index

pair<int,int> o[MAXN];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n);
	REP(i,n) mxlen[i]=1,prv[i]=-1;

	for(int al=0,ar=al;al<n;al=ar) {
		while(ar<n&&o[ar].first==o[al].first) ++ar;
		int bl=ar,br=bl; while(br<n&&o[br].first==o[al].first+1) ++br;
		int ai=al;
		FOR(bi,bl,br) {
			while(ai<ar&&o[ai].second<o[bi].second) ++ai;
			if(ai!=al) mxlen[o[bi].second]=mxlen[o[ai-1].second]+1,prv[o[bi].second]=o[ai-1].second;
		}
	}
	//REP(i,n) printf("%d: a=%d mxlen=%d prv=%d\n",i,a[i],mxlen[i],prv[i]);

	int idx=0; REP(i,n) if(mxlen[i]>mxlen[idx]) idx=i;
	nret=0; for(int x=idx;x!=-1;x=prv[x]) ret[nret++]=x; reverse(ret,ret+nret); assert(nret==mxlen[idx]);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}