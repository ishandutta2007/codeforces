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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<ll> res;
		for(ll i=n-1;i>=0;i--){
			ll pos=-1;
			fore(j,0,SZ(a)){
				if(a[j]==i)pos=j;
			}
			res.pb((pos+1)%SZ(a));
			vector<ll> na;
			fore(j,pos+1,SZ(a))na.pb(a[j]);
			fore(j,0,pos)na.pb(a[j]);
			a=na;
		}
		reverse(ALL(res));
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}