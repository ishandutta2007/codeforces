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

ll n;
ll a[5050];

ll dp[5050][5050];

set<ll> st;
map<ll,ll> mp;
vector<ll> val;

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==n-1){
		if(a[x]<=val[y])return res=0;
		return res=1;
	}
	res=9e18;
	if(a[x]<=val[y]){
		res=f(x+1,mp[a[x]]);
	}else{
		res=min(res,f(x+1,y)+1);
		if(a[x+1]>val[y]){
			ll mini=min(a[x],a[x+1]);
			res=min(res,f(x+1,mp[mini])+mini-val[y]+(a[x]>mini?1:0));
		}
	}
	//cout<<x<<" "<<y<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)st.insert(a[i]);
	st.insert(0);
	ll va=0;
	for(auto i:st)mp[i]=va++,val.pb(i);
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	
	return 0;
}