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
		string s; cin>>s;
		s="0"+s;
		vector<ll> a(n+1);
		fore(i,0,n)cin>>a[i+1];
		vector<pair<ll,ll>> v;
		ll ul=-1;
		for(ll i=n;i>=0;i--){
			if(ul==-1&&s[i]=='1')ul=i;
			if(ul!=-1&&s[i]=='0'){
				v.pb({i,ul});
				ul=-1;
			}
		}
		ll res=0;
		for(auto i:v){
			ll s=0,mini=1e9;
			fore(j,i.fst,i.snd+1){
				s+=a[j];
				mini=min(mini,a[j]);
			}
			res+=s-mini;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}