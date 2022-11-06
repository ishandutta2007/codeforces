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

ll pot[12];

int main(){FIN;
	pot[0]=1;
	fore(i,1,12)pot[i]=10ll*pot[i-1];
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; k++;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(i,0,n){
			ll maxi=k;
			if(i<n-1){
				maxi=min(maxi,pot[a[i+1]-a[i]]-1);
			}
			res+=pot[a[i]]*maxi;
			k-=maxi;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}