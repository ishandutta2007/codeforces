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
		map<string,ll> mp;
		vector<string> a(n);
		fore(i,0,n)cin>>a[i];
		for(auto i:a){
			mp[i]++;
			string pr=i,su=i;
			pr[0]='.';
			su[1]='.';
			mp[pr]++;
			mp[su]++;
		}
		ll res=0;
		for(auto i:a){
			string pr=i,su=i;
			pr[0]='.';
			su[1]='.';
			res+=mp[pr]+mp[su]-2ll*mp[i];
		}
		cout<<res/2<<"\n";
	}
	
	return 0;
}