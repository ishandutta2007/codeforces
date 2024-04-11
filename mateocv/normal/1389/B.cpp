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
		ll n,k,z; cin>>n>>k>>z;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(j,0,z+1){
			ll maxi=0,s=0;
			fore(i,0,k+1-2*j){
				s+=a[i];
				if(i>0)maxi=max(maxi,a[i]+a[i-1]);
			}
			if(k+1-2*j<n&&k-2*j>=0){
				maxi=max(maxi,a[k-2*j]+a[k+1-2*j]);
				//cout<<k+1-2*j<<" "<<n<<"\n";
			}
			res=max(res,s+j*maxi);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}