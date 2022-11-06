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
		string s,ss; cin>>s>>ss;
		reverse(ALL(ss));
		vector<pair<ll,ll>> v;
		fore(i,0,n){
			v.pb({min(s[i],ss[i]),max(s[i],ss[i])});
		}
		map<pair<ll,ll>,ll> mp;
		for(auto i:v)mp[i]++;
		ll c=0,eq=0;
		for(auto i:mp){
			if(i.snd&1){
				c++;
				eq=(i.fst.fst==i.fst.snd);
			}
		}
		ll res=0;
		if(n&1){
			res=(c==1&&eq);
		}else{
			res=(c==0);
		}
		cout<<(res?"YES\n":"NO\n");
	}
	
	return 0;
}