#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n,m,nc;
vector<pair<int,pair<int,int> > > g[100005];
vector<int> p[100005];  // valores conocidos si >=0
int a[100005][2];
int dp2[100005][2];
int dp[100005][2][2][2];
bool vis[100005];

int dfs0(int x, int f){
	if(vis[x])return x;
	vis[x]=true;
	int r=x;
	fore(i,0,g[x].size()){
		if(g[x][i].fst!=f){
			r=dfs0(g[x][i].fst,x);
		}
	}
	return r;
}

int go(int x, int pi, int q, int c, int f, int s){
	if(dp[x][pi][q][c]>=0)return dp[x][pi][q][c];
	dp[x][pi][q][c]=0;
	if(g[x].size()==2&&g[x][0].fst==g[x][1].fst){
		// multiedge por separado
		if(g[x][0].snd.fst==g[x][1].snd.fst&&g[x][0].snd.snd==g[x][1].snd.snd){
			dp[x][pi][q][c]=pi?0:4;
		}
		else {
			dp[x][pi][q][c]=2;
		}
		return dp[x][pi][q][c];
	}
	fore(k,0,2){
		int pp=pi;
		fore(i,0,p[x].size())if(p[x][i]==k)pp^=1;
		int cc=c;
		if(f<0&&g[x].size()==2){
			int vx=g[x][1].snd.fst;
			if(vx==k)cc=1,pp^=1;
		}
		if(!q){
			fore(i,0,g[x].size()){
				int y=g[x][i].fst,vx=g[x][i].snd.fst,vy=g[x][i].snd.snd;
				if(y!=f)continue;
				if(vx==k)pp^=1;
			}
		}
		bool l=false;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst,vx=g[x][i].snd.fst,vy=g[x][i].snd.snd;
			if(y==f)continue;
			if(y==s){
				if(c){
					//puts("hola");
					dp[x][pi][q][c]+=pp==0;
				}
				else {
					dp[x][pi][q][c]+=(pp^(vx==k))==0;
				}
			}
			else {
				dp[x][pi][q][c]+=go(y,pp^(vx==k),vx==k,cc,x,s);
				dp[x][pi][q][c]%=MOD;
				//printf("%d %d %d %d %d %d\n",x,pi,q,c,k,dp[x][pi][q][c]);
			}
			l=true;
			break;
		}
		if(!l){
			dp[x][pi][q][c]+=pp==0;
		}
	}
	dp[x][pi][q][c]%=MOD;
	return dp[x][pi][q][c];
}


int main(){
	scanf("%d%d",&m,&n);
	int q=1;
	fore(i,0,m){
		int k;
		scanf("%d",&k);
		if(k==1){
			int x;
			scanf("%d",&x);
			if(x<0)p[-x-1].pb(0);
			else p[x-1].pb(1);
		}
		else {
			int x,y;
			int vx=1,vy=1;
			scanf("%d%d",&x,&y);
			if(x<0){vx=0;x=-x;}
			if(y<0){vy=0;y=-y;}
			if(x==y){
				if(vx==vy)p[x-1].pb(vx);
				else q^=1;
			}
			else {
				g[x-1].pb(mp(y-1,mp(vx,vy)));
				g[y-1].pb(mp(x-1,mp(vy,vx)));
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	fore(i,0,n){
		if(vis[i])continue;
		int x=dfs0(i,-1);
		a[nc][0]=go(x,0,0,0,-1,x);
		a[nc][1]=go(x,1,0,0,-1,x);
		//printf("%d %d %d\n",x+1,a[nc][0],a[nc][1]);
		nc++;
	}
	//puts("x pi q c dp");
	//fore(x,0,n)fore(pi,0,2)fore(q,0,2)fore(c,0,2)if(dp[x][pi][q][c]>=0)printf("%d %d %d %d %d\n",x,pi,q,c,dp[x][pi][q][c]);

	dp2[nc][0]=1;
	dp2[nc][1]=0;
	for(int i=nc-1;i>=0;--i){
		for(int j=0;j<2;++j){
			dp2[i][j]=(1LL*a[i][0]*dp2[i+1][j])%MOD;
			dp2[i][j]=(dp2[i][j]+(1LL*a[i][1]*dp2[i+1][j^1])%MOD)%MOD;
		}
	}
	printf("%d\n",dp2[0][q]);
	return 0;
}