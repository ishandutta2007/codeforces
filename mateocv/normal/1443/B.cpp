#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		string s; cin>>s;
		vector<ll> v;
		ll l=SZ(s),r=-1;
		fore(i,0,SZ(s)){
			if(s[i]=='1'){
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(l>r){
			cout<<"0\n";
			continue;
		}
		ll va=0;
		fore(i,l,r+1){
			if(s[i]=='0')va++;
			else{
				if(va!=0){
					v.pb(va);
					va=0;
				}
			}
		}
		sort(ALL(v));
		reverse(ALL(v));
		//for(auto i:v)cout<<i<<" "; cout<<"\n";
		ll res=(SZ(v)+1)*a;
		while(SZ(v)){
			if(b*v.back()-a<0){
				res+=b*v.back()-a;
				v.pop_back();
			}else{
				break;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}