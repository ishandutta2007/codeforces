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
		if(n<=30){
			cout<<"NO\n";
		}else if(n==36||n==40||n==44){
			cout<<"YES\n6 10 15 "<<n-31<<"\n";
		}else{
			cout<<"YES\n6 10 14 "<<n-30<<"\n";
		}
	}
	
	
	return 0;
}