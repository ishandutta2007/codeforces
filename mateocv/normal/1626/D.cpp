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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<ll> cp(20),cs(20);
		fore(i,0,n+1){
			if(i==0||i==n||a[i-1]<a[i]){
				fore(j,0,20){
					if(i<=(1ll<<j))cp[j]=max(cp[j],i);
					if(n-i<=(1ll<<j))cs[j]=max(cs[j],n-i);
				}
			}
		}
		ll res=1e18;
		fore(i,0,20){
			fore(j,0,20){
				fore(k,0,20){
					if(cp[i]+cs[j]<=n){
						if(n-cp[i]-cs[j]<=(1ll<<k))res=min(res,(1ll<<i)+(1ll<<j)+(1ll<<k)-n);
					}else{
						res=min(res,(1ll<<i)+(1ll<<j)+(1ll<<k)-n);
					}
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}