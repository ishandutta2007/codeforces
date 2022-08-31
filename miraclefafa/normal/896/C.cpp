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
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,m,vmax,a[N];
ll seed;
int op,l,r,x,y;

ll rnd() {
	ll ret=seed;
    seed = (seed * 7+13) % 1000000007;
    return ret;
}

map<int,ll> st;
int main() {
	scanf("%d%d%lld%d",&n,&m,&seed,&vmax);
	rep(i,1,n+1) a[i]=rnd()%vmax+1,st[i]=a[i];
	st[n+1]=0;
//	rep(i,1,n+1) printf("%d ",a[i]); puts("");
	rep(i,0,m) {
		op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
		if (l>r) swap(l,r);
		if (op==3) x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if (op==4) y=rnd()%vmax+1; else y=-1;
//		printf("%d %d %d %d %d\n",op,l,r,x,y);
		auto it=--st.upper_bound(l); st[l]=it->se;
		it=--st.upper_bound(r+1); st[r+1]=it->se;
		if (op==1) {
			auto it=st.lower_bound(l);
			while (it->fi!=r+1) {
				it->se+=x;
				++it;
			}
		} else if (op==3) {
			auto it=st.lower_bound(l);
			vector<pair<ll,int> > cand;
			while (it->fi!=r+1) {
				auto nit=it; ++nit;
				cand.pb(mp(it->se,nit->fi-it->fi));
				it=nit;
			}
			sort(all(cand));
			rep(i,0,SZ(cand)) {
				x-=cand[i].se;
				if (x<=0) { printf("%lld\n",cand[i].fi); break; }
			}
		} else if (op==4) {
			auto it=st.lower_bound(l);
			vector<pair<ll,int> > cand;
			while (it->fi!=r+1) {
				auto nit=it; ++nit;
				cand.pb(mp(it->se,nit->fi-it->fi));
				it=nit;
			}
			ll ret=0;
			rep(i,0,SZ(cand)) {
				ret=(ret+cand[i].se*powmod(cand[i].fi%y,x,y))%y;
			}
			printf("%lld\n",ret);
		} else {
			while (1) {
				auto it=st.lower_bound(l);
				if (it->fi==r+1) break;
				st.erase(it);
			}
			st[l]=x;
		}
//		for (auto p:st) printf("%d,%lld ",p.fi,p.se); puts("");
	}
}