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

const ll MOD=1000000007;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> u(n);
		fore(i,0,n)u[a[i]]=i;
		ll l=u[0],r=u[0];
		ll res=1;
		fore(i,1,n){
			if(l<=u[i]&&u[i]<=r){
				res=res*(r-l+1-i)%MOD;
			}else{
				l=min(l,u[i]);
				r=max(r,u[i]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}