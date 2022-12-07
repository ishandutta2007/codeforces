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
		ll n; cin>>n;
		string s; cin>>s;
		ll res=0;
		fore(i,0,n){
			vector<ll> c(10);
			ll maxi=0,d=0;
			fore(j,i,min(n,i+202)){
				if(c[s[j]-'0']==0){
					d++;
				}
				c[s[j]-'0']++;
				maxi=max(maxi,c[s[j]-'0']);
				if(maxi<=d)res++;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}