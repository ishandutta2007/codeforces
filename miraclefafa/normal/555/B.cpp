#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int n,m,ret[N];
ll l[N],r[N],x;
set<pair<ll,ll> > st;
pair<pair<ll,ll>,int> p[N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%lld%lld",l+i,r+i);
	rep(i,0,n-1) p[i]=mp(mp(r[i+1]-l[i],l[i+1]-r[i]),i);
	sort(p,p+n-1);
	rep(i,0,m) scanf("%lld",&x),st.insert(mp(x,i));
	rep(i,0,n-1) {
		set<pair<ll,ll> >::iterator it=st.lower_bound(mp(p[i].fi.se,-1));
		if (it==st.end()||it->fi>p[i].fi.fi) {
			puts("No");
			return 0;
		} else {
			ret[p[i].se]=it->se+1;
			st.erase(it);
		}
	}
	puts("Yes");
	rep(i,0,n-1) printf("%d\n",ret[i]);
}