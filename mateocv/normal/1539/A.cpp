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
		ll n,x,t; cin>>n>>x>>t;
		ll maxi=t/x;
		if(n<=maxi){
			cout<<n*(n-1)/2<<"\n";
		}else{
			cout<<maxi*(maxi-1)/2+maxi*(n-maxi)<<"\n";
		}
	}
	
	return 0;
}