#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			if(i==n-1){
				cout<<"YES\n"; break;
			}
			if(a[i+1]-a[i]>m+k){
				cout<<"NO\n"; break;
			}
			if(a[i+1]-a[i]>k)m-=(a[i+1]-a[i]-k);
			else{
				ll p=max(0ll,a[i+1]-k);
				m+=a[i]-p;
			}
		}
	}
	return 0;
}