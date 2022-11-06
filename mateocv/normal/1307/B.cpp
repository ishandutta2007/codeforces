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
		ll n,x; cin>>n>>x;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll maxi=0;
		ll br=0;
		fore(i,0,n){
			maxi=max(maxi,a[i]);
			if(x==a[i]){
				cout<<1<<'\n'; br++; break;
			}
		}
		if(br)continue;
		cout<<max((x+maxi-1)/maxi,2ll)<<"\n";
	}
	
	return 0;
}