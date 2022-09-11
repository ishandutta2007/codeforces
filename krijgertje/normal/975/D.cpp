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
struct G { int sx,vx,vy; ll z; };
bool operator<(const G &a,const G &b) {
	if(a.z!=b.z) return a.z<b.z;
	if(a.vx!=b.vx) return a.vx<b.vx;
	return false;
}

int n,a,b;
G g[MAXN];


void run() {
	scanf("%d%d%d",&n,&a,&b);
	REP(i,n) scanf("%d%d%d",&g[i].sx,&g[i].vx,&g[i].vy);

	REP(i,n) g[i].z=g[i].vy-(ll)a*g[i].vx;
	sort(g,g+n);

	ll ret=0;
	for(int l1=0,r1=l1;l1<n;l1=r1) {
		while(r1<n&&g[l1].z==g[r1].z) ++r1;
		int cnt1=r1-l1;
		ret+=(ll)cnt1*(cnt1-1);
		for(int l2=l1,r2=l2;l2<r1;l2=r2) {
			while(r2<r1&&g[l2].vx==g[r2].vx) ++r2;
			int cnt2=r2-l2;
			ret-=(ll)cnt2*(cnt2-1);
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}