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
		ll res[n];
		vector<ll> v[2];
		ll va=0;
		fore(i,0,n){
			ll b=s[i]-'0';
			if(SZ(v[b^1])){
				ll ba=v[b^1].back();
				res[i]=ba;
				v[b^1].pop_back();
				v[b].pb(ba);
			}else{
				v[b].pb(va);
				res[i]=va;
				va++;
			}
		}
		cout<<va<<"\n";
		fore(i,0,n)cout<<res[i]+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}