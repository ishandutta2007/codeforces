#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
typedef long long ll;
const int MAXN=5e6,mod=998244353;
#define lc ch[u][0]
#define rc ch[u][1]
int n,x,cntp=1,ch[MAXN][2],siz[MAXN],p[MAXN],f[MAXN];
int ans;
ll pw[MAXN];
void Dfs(int u,int d){
	if(d<0){
		f[u]=(pw[siz[u]]-1)*(pw[siz[p[u]]]-1)%mod;
		return ;
	}
	int t=x>>d&1;
	if(lc){
		p[lc]=ch[p[u]][t];
		Dfs(lc,d-1);
	}
	if(rc){
		p[rc]=ch[p[u]][t^1];
		Dfs(rc,d-1);
	}
	if(t) f[u]=(1ll*f[lc]*f[rc]%mod+(pw[siz[rc]]+pw[siz[ch[p[u]][0]]]-1)%mod*f[lc]+(pw[siz[lc]]+pw[siz[ch[p[u]][1]]]-1)%mod*f[rc]+
			(pw[siz[lc]]-1)*(pw[siz[ch[p[u]][0]]]-1)%mod+(pw[siz[rc]]-1)*(pw[siz[ch[p[u]][1]]]-1)%mod)%mod;
	else f[u]=(f[lc]+f[rc])%mod;
	if(t&&u==p[u]) ans=(ans+f[rc]+pw[siz[lc]]+pw[siz[rc]]-2)%mod,assert(f[lc]==f[rc]);
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&x);
	pw[0]=1;
	for(int i=1; i<=n; i++)
		pw[i]=pw[i-1]*2%mod;
	x=x<<1|1;
	while(n--){
		int a;
		scanf("%d",&a);
		a<<=1;
		int u=1;
		for(int i=30; ~i; i--){
			int t=a>>i&1;
			if(!ch[u][t]) ch[u][t]=++cntp;
			u=ch[u][t];
			siz[u]++;
		}
	}
	p[1]=1;
	Dfs(1,30);
	printf("%d\n",ans);
	return 0;
}
// fuck ccf