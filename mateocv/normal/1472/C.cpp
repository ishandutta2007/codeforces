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
		ll maxi[n];
		maxi[n-1]=a[n-1];
		for(ll i=n-2;i>=0;i--){
			maxi[i]=a[i];
			if(i+a[i]<n){
				maxi[i]+=maxi[i+a[i]];
			}
		}
		ll res=0;
		fore(i,0,n)res=max(res,maxi[i]);
		cout<<res<<"\n";
	}
	
	return 0;
}