#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<pair<int,bool> > g[512];
vector<pair<int,bool> > ig[512];
int n,m;
bitset<512> w[2][64][2][512];
ll dp[512][64][2];

ll f(int x, int k, int b){
	if(dp[x][k][b]>=0)return dp[x][k][b];
	ll r=0;
	fore(y,0,n){
		if(w[0][k][b][x][y]){r=1LL<<k;break;}
	}
	if(r<(1LL<<k)&&k>0){
		fore(y,0,n){
			if(w[0][k-1][b][x][y]){r=max(r,(1LL<<(k-1))+f(y,k-1,b^1));}
		}
		if(!r)r=f(x,k-1,b);
	}
	return dp[x][k][b]=r;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);a--;b--;
		g[a].pb(mp(b,t));w[0][0][t][a][b]=1;
		ig[b].pb(mp(a,t));w[1][0][t][b][a]=1;
	}
	fore(k,1,61){
		fore(b,0,2){
			fore(x,0,n){
				fore(y,0,n){
					if((w[0][k-1][b][x]&w[1][k-1][b^1][y]).any()){
						w[0][k][b][x][y]=w[1][k][b][y][x]=1;
						//printf("%d %d  %d %d\n",k,b,x+1,y+1);
					}
				}
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	ll r=0;
	fore(x,0,n)r=max(r,f(x,60,0));
	if(r>1000000000000000000LL)puts("-1");
	else printf("%lld\n",r);
	return 0;
}