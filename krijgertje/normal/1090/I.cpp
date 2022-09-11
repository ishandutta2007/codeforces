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
typedef unsigned long long ull;  
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=20000000;

int n;

ll gl,gr,gx,gy,gz,gb1,gb2;
ll b[MAXN];
ll a[MAXN];

ll c[MAXN]; int nc;

ll solveneg() {
	nc=0; ll ret=LLONG_MAX;
	REP(i,n) {
		if(a[i]>=0) continue;
		while(nc>=2&&c[nc-2]<a[i]) --nc;
		if(nc>=1&&c[nc-1]<a[i]) {
			ret=min(ret,a[i]*c[nc-1]);
			--nc;
		}
		if(nc==0||a[i]<c[nc-1]) c[nc++]=a[i];
	}
	return ret;
}

ll solvenonneg() {
	ll ret=LLONG_MAX;
	ll mn=a[0];
	FOR(i,1,n) {
		if(a[i]>=0&&mn<a[i]) ret=min(ret,mn*a[i]);
		mn=min(mn,a[i]);
	}
	return ret;
}

ll solve() {
	//printf("a:"); REP(i,n) printf(" %lld",a[i]); puts("");
	ll ans1=solveneg();
	ll ans2=solvenonneg();
	return min(ans1,ans2);
}

ll gmlt(ll x,ll y) { return ((ull)x)*((ull)y)%(1ULL<<32); }
void run() {
	scanf("%d%lld%lld%lld%lld%lld%lld%lld",&n,&gl,&gr,&gx,&gy,&gz,&gb1,&gb2);
	b[0]=gb1; b[1]=gb2; FOR(i,2,n) b[i]=(gmlt(b[i-2],gx)+gmlt(b[i-1],gy)+gz)%(1LL<<32);
	REP(i,n) a[i]=b[i]%(gr-gl+1)+gl;
	ll ans=solve();
	if(ans==LLONG_MAX) printf("IMPOSSIBLE\n"); else printf("%lld\n",ans);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}