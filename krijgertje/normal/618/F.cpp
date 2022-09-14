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

const int MAXN=1000000;

int n;
int a[MAXN],b[MAXN];
ll asum[MAXN+1],bsum[MAXN+1];
int idx[MAXN+1];
int diff[MAXN];
bool inv;

void sol(int al,int ah,int bl,int bh) {
	//printf("sol(%d..%d,%d..%d)\n",al,ah,bl,bh);
	if(inv) swap(al,bl),swap(ah,bh);
	printf("%d\n",ah-al); FOR(i,al,ah) { if(i!=al) printf(" "); printf("%d",i+1); } puts("");
	printf("%d\n",bh-bl); FOR(i,bl,bh) { if(i!=bl) printf(" "); printf("%d",i+1); } puts("");
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]); inv=false;
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	bsum[0]=0; REP(i,n) bsum[i+1]=bsum[i]+b[i];
	if(asum[n]>bsum[n]) { inv=true; REP(i,n) swap(a[i],b[i]); REPE(i,n) swap(asum[i],bsum[i]); }
	//REPE(i,n) printf("%lld ",asum[i]); puts("");
	//REPE(i,n) printf("%lld ",bsum[i]); puts("");
	memset(diff,-1,sizeof(diff));
	REPE(i,n) {
		idx[i]=i==0?0:idx[i-1];
		while(bsum[idx[i]+1]<=asum[i]) ++idx[i];
		int cur=(int)(asum[i]-bsum[idx[i]]);
		//printf("[..%d) [..%d) -> %d\n",i,idx[i],cur);
		if(diff[cur]==-1) diff[cur]=i; else { sol(diff[cur],i,idx[diff[cur]],idx[i]); return; }
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}