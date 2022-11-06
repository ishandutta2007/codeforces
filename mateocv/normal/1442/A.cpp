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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll mini=a[0],maxi=0;
		fore(i,1,n){
			if(a[i]<mini+maxi){
				mini-=(mini+maxi-a[i]);
			}else if(a[i]>mini+maxi){
				maxi+=a[i]-(mini+maxi);
			}
		}
		if(mini>=0){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}