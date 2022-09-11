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

const int MAXN=100000+2;

int n,mxjump;
int a[MAXN];

set<int> avail;
map<int,int> have;

ll solve() {
	avail.clear(); FOR(i,1,n) if(a[i]>0) avail.insert(i);
	have.clear(); have[0]=a[0]; a[0]=0;
	ll ret=0;
	while(SZ(have)>0) {
		auto hit=have.begin(); int at=hit->first,cnt=hit->second;
		auto ait=avail.upper_bound(at+mxjump); if(ait==avail.begin()) { have.erase(hit); continue; } --ait; int to=*ait; if(to<=at) { have.erase(hit); continue; }
		int now=min(cnt,a[to]);
		//printf("%d go from %d to %d\n",now,at,to,at);
		cnt-=now; if(cnt==0) have.erase(hit); else hit->second-=now;
		a[to]-=now; if(a[to]==0) avail.erase(ait);
		if(to==n-1) ret+=now; else have[to]+=now;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&mxjump); n+=1; FOR(i,1,n-1) scanf("%d",&a[i]); a[0]=a[n-1]=INT_MAX;
	//n=MAXN; a[0]=a[n-1]=INT_MAX; FOR(i,1,n-1) a[i]=10000; mxjump=99;
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");

	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}