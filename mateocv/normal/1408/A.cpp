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
		ll a[n],b[n],c[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n)cin>>c[i];
		ll res[n];
		res[0]=a[0];
		fore(i,1,n-1){
			if(a[i]==res[i-1]){
				res[i]=b[i];
			}else{
				res[i]=a[i];
			}
		}
		pair<ll,ll> p={res[0],res[n-2]};
		if(a[n-1]!=p.fst&&a[n-1]!=p.snd){
			res[n-1]=a[n-1];
		}
		if(b[n-1]!=p.fst&&b[n-1]!=p.snd){
			res[n-1]=b[n-1];
		}
		if(c[n-1]!=p.fst&&c[n-1]!=p.snd){
			res[n-1]=c[n-1];
		}
		fore(i,0,n)cout<<res[i]<<" "; cout<<"\n";
	}
	
	return 0;
}