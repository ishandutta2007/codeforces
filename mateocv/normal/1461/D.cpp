#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=100005;

ll a[MAXN];
set<ll> st;

void solve(ll l, ll r){
	ll sum=0;
	ll mini=a[l],maxi=a[r-1];
	ll mid=(mini+maxi)/2;
	fore(i,l,r)sum+=a[i];
	st.insert(sum);
	if(mini!=maxi){
		ll m=-1;
		fore(i,l,r-1){
			if(a[i]<=mid&&a[i+1]>mid){
				m=i+1;
			}
		}
		assert(m!=-1);
		solve(l,m);
		solve(m,r);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n)cin>>a[i];
		st.clear();
		sort(a,a+n);
		solve(0,n);
		while(q--){
			ll s; cin>>s;
			if(st.count(s))cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	
	return 0;
}