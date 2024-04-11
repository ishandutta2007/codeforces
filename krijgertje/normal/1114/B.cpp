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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n,needeach,needparts;
int a[MAXN];
int ans[MAXN],nans;

pair<int,int> o[MAXN];
bool use[MAXN];



ll solve() {
	REP(i,n) o[i]=MP(-a[i],i); sort(o,o+n);
	REP(i,n) use[i]=false; REP(i,needeach*needparts) use[o[i].second]=true;
	nans=0; int nseen=0; REP(i,n) if(use[i]) { ++nseen; if(nseen%needeach==0&&nseen!=needeach*needparts) ans[nans++]=i; }
	ll ret=0; REP(i,n) if(use[i]) ret+=a[i]; return ret;
}

void run() {
	scanf("%d%d%d",&n,&needeach,&needparts);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}