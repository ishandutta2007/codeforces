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
		vector<string> s[3];
		map<string,ll> mp;
		fore(k,0,3){
			fore(i,0,n){
				string x; cin>>x;
				s[k].pb(x);
				mp[x]++;
			}
		}
		ll res[3]={0,0,0};
		fore(k,0,3){
			for(auto i:s[k]){
				if(mp[i]==1)res[k]+=3;
				else if(mp[i]==2)res[k]+=1;
			}
		}
		fore(k,0,3)cout<<res[k]<<" ";
		cout<<"\n";
	}
	
	return 0;
}