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
		char c; cin>>c;
		string s; cin>>s;
		s+=s;
		vector<ll> v;
		fore(i,0,SZ(s)){
			if(s[i]=='g')v.pb(i);
		}
		ll res=0;
		fore(i,0,n){
			if(s[i]==c){
				auto pos=*(lower_bound(ALL(v),i))-i;
				res=max(res,pos);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}