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

int n,m,q,u,v,w,l,r,f[2010];
vector<pair<int,pair<PII,int> > > e;
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		--u; --v;
		e.pb(mp(w,mp(mp(u,v),i+1)));
	}
	sort(all(e)); reverse(all(e));
	rep(i,0,q) {
		scanf("%d%d",&l,&r);
//		--l; --r;
		rep(j,0,2*n) f[j]=j;
		bool val=1;
		rep(j,0,m) if (e[j].se.se>=l&&e[j].se.se<=r) {
			u=e[j].se.fi.fi,v=e[j].se.fi.se;
//			printf("%d %d\n",u,v);
			if (find(2*u)==find(2*v)) {
				printf("%d\n",e[j].fi);
				val=0;
				break;
			} else {
				f[find(2*u)]=find(2*v+1);
				f[find(2*u+1)]=find(2*v);
			}
		}
		if (val==1) {
			puts("-1");
		}
	}
}