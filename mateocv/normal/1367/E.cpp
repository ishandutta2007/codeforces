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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		ll cant[26];
		mset(cant,0);
		fore(i,0,n)cant[s[i]-'a']++;
		//fore(i,0,26)cout<<cant[i]<<" "; cout<<"\n";
		ll res=1;
		fore(i,1,n+1){
			ll mini=i/__gcd(k%i,i);
			//cout<<i<<" "<<mini<<"\n";
			ll tot=0;
			fore(j,0,26){
				tot+=mini*(cant[j]/mini);
			}
			if(tot>=i)res=max(res,i);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}