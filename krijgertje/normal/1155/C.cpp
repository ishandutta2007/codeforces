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

const int MAXA=300000;
const int MAXOPT=300000;

int na,nopt;
ll a[MAXA];
ll opt[MAXOPT];

pair<ll,int> solve() {
	ll g=a[1]-a[0];
	FOR(i,2,na) g=gcd(g,a[i]-a[0]);
	REP(i,nopt) if(g%opt[i]==0) return MP(a[0],i);
	return MP(-1LL,-1);
}

void run() {
	scanf("%d%d",&na,&nopt);
	REP(i,na) scanf("%lld",&a[i]);
	REP(i,nopt) scanf("%lld",&opt[i]);
	pair<ll,int> ans=solve();
	if(ans==MP(-1LL,-1)) { printf("NO\n"); return; }
	printf("YES\n%lld %d\n",ans.first,ans.second+1);
}

int main() {
	run();
	return 0;
}