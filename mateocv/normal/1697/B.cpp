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
	ll n,q; cin>>n>>q;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	vector<ll> sump={0};
	for(auto i:a)sump.pb(sump.back()+i);
	//ll res=0;
	while(q--){
		ll x,y; cin>>x>>y;
		cout<<sump[n-x+y]-sump[n-x]<<"\n";
	}
	//cout<<res<<"\n";
	
	return 0;
}