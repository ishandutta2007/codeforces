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
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll res=1e18,pos=0;
		fore(i,0,n-k){
			if((a[i+k]-a[i]+1)/2<res){
				res=(a[i+k]-a[i]+1)/2;
				pos=a[i]+res;
			}
		}
		cout<<pos<<"\n";
	}
	
	return 0;
}