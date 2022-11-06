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
typedef int ll;

const int MAXN=77;
ll n,m,k;
ll dp[MAXN][MAXN][MAXN][MAXN];

ll a[MAXN][MAXN];

ll INF=(1ll<<30);

ll f(ll x, ll y, ll z, ll c){
	ll &res=dp[x][y][z][c];
	if(res!=-1)return res;
	if(x==n&&y==0){
		if(z==0)return res=0;
		return res=-INF;
	}
	if(y==m-1){
		res=f(x+1,0,z,m/2);
		if(c){
			res=max(res,f(x+1,0,(z+a[x][y])%k,m/2)+a[x][y]);
		}
	}else{
		res=f(x,y+1,z,c);
		if(c){
			res=max(res,f(x,y+1,(z+a[x][y])%k,c-1)+a[x][y]);
		}
	}
	return res;
}

int main(){FIN;
	cin>>n>>m>>k;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
		}
	}
	mset(dp,-1);
	ll res=f(0,0,0,m/2);
	cout<<res<<"\n";
	return 0;
}