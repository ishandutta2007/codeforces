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
		sort(a,a+n);
		ll s=0;
		fore(i,0,n)s+=a[i];
		if(s/n>=x){
			cout<<n<<"\n";
			continue;
		}
		fore(i,0,n){
			s-=a[i];
			if(i==n-1){
				cout<<0<<"\n"; break;
			}
			if(s/(n-1-i)>=x){
				cout<<n-1-i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}