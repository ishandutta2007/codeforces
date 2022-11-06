#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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
		ll a[2*n];
		fore(i,0,2*n)cin>>a[i];
		sort(a,a+2*n);
		ll br=0;
		ll b[n];
		fore(i,0,2*n){
			if(i&1){
				b[i/2]=a[i];
				if(a[i]!=a[i-1]||a[i]&1){
					br++; break;
				}
			}
		}
		ll va=0,ul=9e18;
		//fore(i,0,n)cout<<b[i]<<" ";
		//cout<<"\n";
		for(ll i=n-1;i>=0;i--){
			//cout<<va<<" "<<ul<<"\n";
			if((b[i]-va)<=0||(b[i]-va)%(2ll*(i+1))!=0||ul<=(b[i]-va)/(2ll*(i+1))){
				br++; break;
			}else{
				ul=(b[i]-va)/(2ll*(i+1));
				va+=(b[i]-va)/(i+1);
			}
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}