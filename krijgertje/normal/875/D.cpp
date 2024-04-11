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
const int MAXBIT=29;

int n;
int a[MAXN];
int l[MAXN],r[MAXN];
int prv[MAXN];

int lst[MAXBIT+1];
pair<int,int> o[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REPE(k,MAXBIT) lst[k]=-1; REP(i,n) { int mx=-1; REPE(k,MAXBIT) if((a[i]&(1<<k))==0) mx=max(mx,lst[k]); else lst[k]=i; l[i]=mx+1; }
	REPE(k,MAXBIT) lst[k]=n; for(int i=n-1;i>=0;--i) { int mn=n; REPE(k,MAXBIT) if((a[i]&(1<<k))==0) mn=min(mn,lst[k]); else lst[k]=i; r[i]=mn-1; }
	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n); REP(i,n) prv[i]=-1; FOR(i,1,n) if(o[i-1].first==o[i].first) prv[o[i].second]=o[i-1].second;
	REP(i,n) if(prv[i]!=-1) l[i]=max(l[i],prv[i]+1);

	ll ret=(ll)n*(n+1)/2;
	REP(i,n) {
		ll cur=(ll)(i-l[i]+1)*(r[i]-i+1);
		ret-=cur;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}