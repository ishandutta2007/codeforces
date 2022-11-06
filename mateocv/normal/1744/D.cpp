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

ll v2(ll x){
	ll res=0;
	while(x%2==0){
		x/=2;
		res++;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll va=n;
		vector<ll> v;
		fore(i,0,n){
			va-=v2(a[i]);
			v.pb(v2(i+1));
		}
		if(va<=0){
			cout<<"0\n";
			continue;
		}
		sort(ALL(v));
		//for(auto i:v)cout<<i<<" "; cout<<"\n";
		ll res=0;
		while(SZ(v)){
			va-=v.back();
			v.pop_back();
			res++;
			if(va<=0)break;
		}
		if(va<=0)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}