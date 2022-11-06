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

const int MAXN=505;

ll ch[MAXN][MAXN];
ll cv[MAXN][MAXN];
ll dp[MAXN][MAXN][12];

ll n,m,k;

bool val(ll x, ll y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

vector<pair<ll,ll>> dir={{1,0},{0,1},{-1,0},{0,-1}};

ll cost(pair<ll,ll> a, pair<ll,ll> b){
	if(a.fst==b.fst){
		return ch[min(a.fst,b.fst)][min(a.snd,b.snd)];
	}else{
		return cv[min(a.fst,b.fst)][min(a.snd,b.snd)];
	}
}

ll INF=(1ll<<60);

ll f(ll x, ll y, ll z){
	ll &res=dp[x][y][z];
	if(res>=0)return res;
	if(z==0)return res=0;
	res=INF;
	for(auto ii:dir){
		ll xx=x+ii.fst,yy=y+ii.snd;
		if(val(xx,yy)){
			res=min(res,cost({x,y},{xx,yy})+f(xx,yy,z-1));
		}
	}
	return res;
}

int main(){FIN;
	 cin>>n>>m>>k;
	fore(i,0,n){
		fore(j,0,m-1){
			cin>>ch[i][j];
		}
	}
	fore(i,0,n-1){
		fore(j,0,m){
			cin>>cv[i][j];
		}
	}
	mset(dp,-1);
	fore(i,0,n){
		fore(j,0,m){
			if(k&1)cout<<"-1 ";
			else cout<<2ll*f(i,j,k/2)<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}