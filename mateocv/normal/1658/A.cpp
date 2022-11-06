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
		vector<ll> v;
		fore(i,0,n){
			if(s[i]=='0')v.pb(i);
		}
		ll res=0;
		fore(i,0,SZ(v)-1){
			res+=max(0ll,3-(v[i+1]-v[i]));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}