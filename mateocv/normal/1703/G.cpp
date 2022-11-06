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

ll n,k;

ll av[100005][40];

ll dp[100005][40];

ll vis[100005][40];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(vis[x][y])return res;
	vis[x][y]=1;
	if(x==n)return res=0;
	res=0;
	res=max(res,av[x][y]-k+f(x+1,y));
	if(y<35)res=max(res,av[x][y+1]+f(x+1,y+1));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			av[i][0]=a[i];
			fore(j,1,40)av[i][j]=av[i][j-1]/2;
		}
		fore(i,0,n+1){
			fore(j,0,40){
				vis[i][j]=0;
			}
		}
		cout<<f(0,0)<<"\n";
	}
	
	return 0;
}