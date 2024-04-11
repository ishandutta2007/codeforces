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
		fore(i,0,n)cin>>a[i];
		ll g[2]={0,0};
		fore(i,0,n){
			g[i&1]=__gcd(g[i&1],a[i]);
		}
		ll br[2]={0,0};
		fore(k,0,2){
			fore(i,0,n-1){
				br[k]+=((a[i]%g[k]==0)==(a[i+1]%g[k]==0));
			}
		}
		if(!br[0])cout<<g[0]<<"\n";
		else if(!br[1])cout<<g[1]<<"\n";
		else cout<<"0\n";
	}
	
	return 0;
}