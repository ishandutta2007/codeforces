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
		ll sump[n+1];
		sump[0]=0;
		fore(i,0,n)sump[i+1]=sump[i]+s[i]-'0'-1;
		map<ll,ll> mp;
		fore(i,0,n+1)mp[sump[i]]++;
		ll res=0;
		for(auto i:mp){
			res+=i.snd*(i.snd-1)/2;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}