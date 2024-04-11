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

ll cdiv(ll x, ll y){
	//cout<<"cd "<<x<<" "<<y<<"\n";
	ll res;
	if(x%y==0)res=x/y;
	else if(x>=0)res=x/y+1;
	else res=x/y;
	//cout<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(k);
		fore(i,0,k)cin>>a[i];
		vector<ll> v;
		fore(i,0,k-1)v.pb(a[i+1]-a[i]);
		ll br=0;
		fore(i,0,SZ(v)-1){
			if(v[i]>v[i+1])br=1;
		}
		if(br){
			cout<<"NO\n";
			continue;
		}
		ll val=cdiv(a[0],n-k+1);
		//cout<<val<<" "<<v[0]<<"\n";
		if(SZ(v)==0||val<=v[0])cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}