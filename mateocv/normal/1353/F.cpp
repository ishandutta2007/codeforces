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

ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n][m];
		vector<ll> v;
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				v.pb(a[i][j]-i-j);
			}
		}
		ll res=INF;
		ll dp[n][m];
		for(auto ii:v){
			for(ll i=n-1;i>=0;i--){
				for(ll j=m-1;j>=0;j--){
					if(a[i][j]<ii+i+j){
						dp[i][j]=INF; continue;
					}
					dp[i][j]=a[i][j]-(ii+i+j);
					if(i==n-1&&j==m-1)continue;
					ll mini=INF;
					if(i+1<n)mini=min(mini,dp[i+1][j]);
					if(j+1<m)mini=min(mini,dp[i][j+1]);
					if(mini<INF)dp[i][j]+=mini;
					else dp[i][j]=INF;
				}
			}
			//cout<<ii<<" "<<dp[0][0]<<"\n";
			res=min(res,dp[0][0]);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}