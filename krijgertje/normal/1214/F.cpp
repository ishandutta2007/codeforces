#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int len,n;
int a[MAXN];
int b[MAXN];
int ans[MAXN];

int abound[MAXN][3];
int bbound[MAXN][3];

pair<int,int> o[MAXN];
int mpa[MAXN];
int mpb[MAXN];

ll solve() {
	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n); REP(i,n) mpa[i]=o[i].second,a[i]=o[i].first;
	REP(i,n) o[i]=MP(b[i],i); sort(o,o+n); REP(i,n) mpb[i]=o[i].second,b[i]=o[i].first;

	REP(i,n) {
		REP(j,3) abound[i][j]=i==0?0:abound[i-1][j];
		while(abound[i][0]<n&&2*(a[i]-b[abound[i][0]])>=len) ++abound[i][0];
		while(abound[i][1]<n&&b[abound[i][1]]<=a[i]) ++abound[i][1];
		while(abound[i][2]<n&&2*(b[abound[i][2]]-a[i])<len) ++abound[i][2];
	}
	REP(i,n) {
		REP(j,3) bbound[i][j]=i==0?0:bbound[i-1][j];
		while(bbound[i][0]<n&&2*(b[i]-a[bbound[i][0]])>=len) ++bbound[i][0];
		while(bbound[i][1]<n&&a[bbound[i][1]]<b[i]) ++bbound[i][1];
		while(bbound[i][2]<n&&2*(a[bbound[i][2]]-b[i])<len) ++bbound[i][2];
	}
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	//printf("b:"); REP(i,n) printf(" %d",b[i]); puts("");
	//REP(i,n) printf("%d: %d/%d/%d | %d/%d/%d\n",i,abound[i][0],abound[i][1],abound[i][2],bbound[i][0],bbound[i][1],bbound[i][2]);

	ll cur=0;
	vector<ll> delta(n,0);
	REP(i,n) {
		int w=0,x=abound[i][0],y=abound[i][1],z=abound[i][2];
		if(w<=i&&i<x) cur+=len-(a[i]-b[i]);
		if(x<=i&&i<y) cur+=a[i]-b[i];
		if(y<=i&&i<z) cur+=b[i]-a[i];
		if(z<=i&&i<n) cur+=len-(b[i]-a[i]);
		{ int t=(x-i+n)%n; delta[t]+=2*a[i]-(ll)len; /*printf("a%d: %d at %d\n",i,2*a[i]-len,t);*/ }
		{ int t=(y-i+n)%n; delta[t]-=2*a[i]; /*printf("a%d: %d at %d\n",i,-2*a[i],t);*/ }
		{ int t=(z-i+n)%n; delta[t]+=2*a[i]+(ll)len; /*printf("a%d: %d at %d\n",i,2*a[i]+len,t);*/ }
		{ int t=(w-i+n)%n; delta[t]-=2*a[i]; /*printf("a%d: %d at %d\n",i,-2*a[i],t);*/ }
	}
	// t: a[i] met b[i+t] -> j=i+t -> a[j-t] met b[j]
	REP(i,n) {
		int w=0,x=bbound[i][0],y=bbound[i][1],z=bbound[i][2];
		{ int t=(i-x+1+n)%n; delta[t]-=2*b[i]; /*printf("b%d: %d at %d\n",i,-2*b[i],t);*/ }
		{ int t=(i-y+1+n)%n; delta[t]+=2*b[i]; /*printf("b%d: %d at %d\n",i,2*b[i],t);*/ }
		{ int t=(i-z+1+n)%n; delta[t]-=2*b[i]; /*printf("b%d: %d at %d\n",i,-2*b[i],t);*/ }
		{ int t=(i-w+1+n)%n; delta[t]+=2*b[i]; /*printf("b%d: %d at %d\n",i,2*b[i],t);*/ }
	}
	//printf("cur=%lld\n",cur);
	//printf("delta:"); REP(i,n) printf(" %lld",delta[i]); puts("");

	ll ret=cur; int offset=0;
	FOR(i,1,n) { 
		cur+=delta[i];
		if(cur<ret) ret=cur,offset=i;
	}
	REP(i,n) ans[mpa[i]]=mpb[(i+offset)%n];
	return ret;
}

void run() {
	scanf("%d%d",&len,&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	REP(i,n) scanf("%d",&b[i]),--b[i];
	printf("%lld\n",solve());
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}