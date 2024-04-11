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

const int MAXN=5000;

int n;
int a[MAXN];

int b[MAXN];
int allb[MAXN],nallb;
int c[MAXN];

int cnt[MAXN],npos;
int ret[MAXN+1];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) if(a[i]==0) { b[i]=0; } else { int x=abs(a[i]); for(int j=2;j*j<=x;++j) while(x%(j*j)==0) x/=j*j; b[i]=a[i]<0?-x:+x; }
	//printf("b:"); REP(i,n) printf(" %d",b[i]); puts("");
	nallb=0; REP(i,n) allb[nallb++]=b[i]; sort(allb,allb+nallb); nallb=unique(allb,allb+nallb)-allb; REP(i,n) c[i]=lower_bound(allb,allb+nallb,b[i])-allb;
	//printf("c:"); REP(i,n) printf(" %d",c[i]); puts("");

	int zero=-1; REP(i,nallb) if(allb[i]==0) zero=i;
	FORE(i,1,n) ret[i]=0;
	REP(l,n) {
		REP(i,nallb) cnt[i]=0; npos=0;
		FOR(r,l,n) {
			if(++cnt[c[r]]==1) ++npos;
			int ans=npos-(zero!=-1&&cnt[zero]>0&&npos>=2?1:0);
			++ret[ans];
		}
	}
	FORE(i,1,n) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}