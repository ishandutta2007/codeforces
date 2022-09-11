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

const int MAXN=35;
const int MAXH=MAXN/2;

int n,mod;
int x[MAXN];

int a[1<<MAXH],na;


void run() {
	scanf("%d%d",&n,&mod);
	REP(i,n) scanf("%d",&x[i]);
	int n1=n/2,n2=n-n1; na=0;
	REP(i,1<<n1) {
		ll sum=0; REP(j,n1) if(i&(1<<j)) sum+=x[j]; a[na++]=sum%mod;
	}
	sort(a,a+na); na=unique(a,a+na)-a; int ret=0;
	REP(i,1<<n2) {
		ll sum=0; REP(j,n2) if(i&(1<<j)) sum+=x[n1+j]; sum%=mod;
		int want=mod-sum-1;
		int idx=lower_bound(a,a+na,want)-a; if(idx>=na||a[idx]>want) --idx; if(idx<0) idx+=na;
		int cur=(sum+a[idx])%mod; if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}