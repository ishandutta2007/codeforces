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

ll INF=2*MOD;

const int MAXN=202;

// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0
ll g[MAXN][MAXN];int nn;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,nn)fore(i,0,nn)if(g[i][k]<INF)fore(j,0,nn)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

ll vr;

bool cmp(ll a, ll b){
	return g[vr][a]<g[vr][b];
}

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll dp[MAXN][MAXN];

ll h;

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==0)return res=1;
	if(y==0)return res=0;
	res=h*(f(x-1,y)+f(x,y-1))%MOD;
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		fore(j,0,n){
			g[i][j]=INF;
		}
	}
	fore(i,0,n)g[i][i]=0;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--; v--;
		g[u][v]=1;
		g[v][u]=1;
	}
	nn=n;
	floyd();
	ll ni=fpow(n,MOD-2);
	mset(dp,-1);
	h=fpow(2,MOD-2);
	/*
	fore(i,0,3){
		fore(j,0,3){
			cout<<"dp: "<<i<<" "<<j<<" "<<": "<<f(i,j)<<"\n";
		}
	}
	*/
	ll res=0;
	fore(i,0,n){
		fore(j,i+1,n){
			//cout<<i<<" "<<j<<":\n";
			vector<ll> w;
			fore(ii,0,n){
				if(g[ii][i]+g[ii][j]==g[i][j])w.pb(ii);
			}
			vr=j;
			sort(ALL(w),cmp);
			//for(auto i:w)cout<<i<<" ";
			//cout<<"\n";
			vector<ll> c(SZ(w));
			fore(ii,0,n){
				c[(g[ii][j]-g[ii][i]+g[i][j])/2]++;
			}
			//for(auto i:c)cout<<i<<" ";
			//cout<<"\n";
			ll va=0;
			fore(ii,0,SZ(w)){
				va=add(va,c[ii]*f(ii,SZ(w)-ii-1)%MOD);
			}
			va=va*ni%MOD;
			res=add(res,va);
		}
	}
	cout<<res<<"\n";
	return 0;
}