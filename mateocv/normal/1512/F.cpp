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
		ll n,c; cin>>n>>c;
		vector<ll> a(n);
		vector<ll> b(n-1);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1)cin>>b[i];
		ll res=9e18;
		ll va=0,s=0;
		fore(i,0,n){
			ll cant=0;
			if(c>s)cant=(c-s+a[i]-1)/a[i];
			res=min(res,va+cant);
			if(i<n-1){
				if(b[i]<=s){
					s-=b[i];
					va++;
				}else{
					ll cc=(b[i]-s+a[i]-1)/a[i];
					va+=cc+1;
					s+=cc*a[i]-b[i];
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}