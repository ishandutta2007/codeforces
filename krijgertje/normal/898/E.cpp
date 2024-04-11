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
int b[MAXN]; // b[i]*b[i]>=a[i]

int opt[MAXN],nopt;

int calc(int x) { int ret=sqrt(1.0*x); while(ret*ret<x) ++ret; return ret; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) b[i]=calc(a[i]);
	int cnt=0; REP(i,n) if(b[i]*b[i]==a[i]) ++cnt;
	if(cnt<n/2) {
		nopt=0;
		REP(i,n) if(b[i]*b[i]>a[i]) opt[nopt++]=min(b[i]*b[i]-a[i],a[i]-(b[i]-1)*(b[i]-1));
		sort(opt,opt+nopt);
		ll ret=0; REP(i,n/2-cnt) ret+=opt[i]; printf("%lld\n",ret);
	} else {
		nopt=0;
		REP(i,n) if(b[i]*b[i]==a[i]) opt[nopt++]=a[i]==0?2:1;
		sort(opt,opt+nopt);
		ll ret=0; REP(i,cnt-n/2) ret+=opt[i]; printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}