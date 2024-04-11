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

ll n,INF=9e18;
ll a[200005];
bool vis[200005][3][3][2];
ll dp[200005][3][3][2];

ll f(ll x, ll y, ll l, ll v){
	ll &res=dp[x][y][l][v];
	if(vis[x][y][l][v])return res;
	vis[x][y][l][v]=1;
	if(x==n){
		if(y==0&&v){
			return res=0;
		}else{
			return res=-INF;
		}
	}
	res=max(f(x+1,y,0,v||l==0)-a[x],f(x+1,(y+2)%3,1,v||l==1)+a[x]);
	//cout<<x<<" "<<y<<" "<<" "<<res<<endl;
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	if(n==1){
		cout<<a[0]<<"\n";
		return 0;
	}
	ll res=f(0,(2*n+2)%3,2,0);
	cout<<res<<"\n";
	return 0;
}