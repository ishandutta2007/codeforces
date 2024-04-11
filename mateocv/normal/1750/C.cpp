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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a,b; cin>>a>>b;
		ll c[2]={0,0};
		fore(i,0,n){
			c[a[i]==b[i]]++;
		}
		if(c[0]&&c[1])cout<<"NO\n";
		else{
			cout<<"YES\n";
			vector<pair<ll,ll>> res;
			vector<ll> pos;
			fore(i,1,n){
				if(a[i]!=a[i-1])pos.pb(i);
			}
			if(SZ(pos)&1)pos.pb(n);
			fore(i,0,SZ(pos)/2)res.pb({pos[2*i],pos[2*i+1]});
			if(c[1]==n&&(SZ(res)&1))res.pb({0,n});
			if(c[0]==n&&!(SZ(res)&1))res.pb({0,n});
			ll p=a[0]-'0';
			for(auto i:res){
				if(i.fst==0)p^=1;
			}
			if(p){
				res.pb({0,1});
				res.pb({1,n});
			}
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i.fst+1<<" "<<i.snd<<"\n";
		}
	}
	
	return 0;
}