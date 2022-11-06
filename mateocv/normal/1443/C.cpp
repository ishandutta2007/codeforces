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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll l=0,r=2e9;
		while(l<=r){
			ll m=(l+r)/2;
			ll sum=0;
			fore(i,0,n){
				if(a[i]>m)sum+=b[i];
			}
			if(sum<=m)r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}