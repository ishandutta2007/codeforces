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

vector<ll> a;

const int MAXN=255;

ll n,m;

ll INF=1e18;

ll dp[MAXN][MAXN][MAXN];

ll f(ll x, ll y, ll z){
	auto &res=dp[x][y][z];
	if(res>=0)return res;
	if(x==n)return 0;
	res=INF;
	if(z+y<=m)res=min(res,f(x+1,y,z+y)+abs(a[x]-z-y));
	if(y<m)res=min(res,f(x,y+1,z));
	return res;
}

int main(){FIN;
	cin>>n>>m;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	reverse(ALL(a));
	fore(i,1,n)a[i]+=a[i-1];
	mset(dp,-1);
	cout<<f(0,0,0)<<"\n";
	
	return 0;
}