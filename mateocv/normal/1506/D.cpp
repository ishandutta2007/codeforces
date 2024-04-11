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
		sort(ALL(a));
		ll maxi=0,ul=-1,c=0;
		fore(i,0,n){
			if(ul==a[i]){
				c++; 
				maxi=max(maxi,c);
			}else{
				ul=a[i];
				c=1;
				maxi=max(maxi,c);
			}
		}
		if(maxi<=(n+1)/2){
			cout<<(n%2)<<"\n";
		}else{
			cout<<n-2*(n-maxi)<<"\n";
		}
	}
	
	return 0;
}