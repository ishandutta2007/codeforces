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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll s=0;
		for(auto i:a)s+=i;
		if(s&1){
			cout<<"-1\n";
			continue;
		}
		s/=2;
		ll val=(s<0?-1:1);
		vector<ll> v;
		fore(i,1,n){
			if(a[i]==val&&(!SZ(v)||v.back()+1<i))v.pb(i);
		}
		if(SZ(v)<abs(s)){
			cout<<"-1\n";
		}else{
			vector<pair<ll,ll>> res;
			while(SZ(v)>abs(s))v.pop_back();
			reverse(ALL(v));
			ll va=0;
			while(va<n){
				if(SZ(v)&&v.back()==va+1){
					res.pb({va,va+1});
					va+=2;
					v.pop_back();
				}else{
					res.pb({va,va});
					va+=1;
				}
			}
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		}
	}
	
	return 0;
}