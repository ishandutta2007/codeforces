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
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<pair<ll,ll>> ed(m);
		fore(i,0,m)cin>>ed[i].fst>>ed[i].snd;
		for(auto &i:ed)i.fst--,i.snd--;
		vector<ll> c(n);
		for(auto i:ed)c[i.fst]++,c[i.snd]++;
		ll res=0;
		if(m&1){
			res=1e9;
			fore(i,0,n){
				if(c[i]&1)res=min(res,a[i]);
			}
			for(auto i:ed){
				if(c[i.fst]%2==0&&c[i.snd]%2==0)res=min(res,a[i.fst]+a[i.snd]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}