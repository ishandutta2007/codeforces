#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000,inf=(1<<29);
int n,w,h,g,p,t;
map<int,VI> pos2;
map<int,vector<PII>> pos;
PII ret[N];
int main() {
	scanf("%d%d%d",&n,&w,&h);
	rep(i,0,n) {
		scanf("%d%d%d",&g,&p,&t);
		if (g==1) {
			pos[p-t].pb(mp(p,i));
			pos2[p-t].pb(p);
		} else {
			pos[p-t].pb(mp(-t,i));
			pos2[p-t].pb(-t+inf);
		}
	}
	for (auto v:pos) {
		int d=v.fi;
		auto p1=v.se;
		auto p2=pos2[d];
		assert(SZ(p1)==SZ(p2));
		sort(all(p1));
		sort(all(p2));
		rep(i,0,SZ(p1)) {
			int x=p2[i],y=d+inf-p2[i];
			x=min(x,w); y=min(y,h);
			ret[p1[i].se]=mp(x,y);
		}
	}
	rep(i,0,n) {
		printf("%d %d\n",ret[i].fi,ret[i].se);
	}
}