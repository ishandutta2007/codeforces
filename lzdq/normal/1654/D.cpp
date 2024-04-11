#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=998244353;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n,pd[MAXN];
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1],ww[MAXN<<1][2];
inline void adde(int u,int v,int w0,int w1){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	ww[cnte][0]=w0;
	ww[cnte][1]=w1;
	h[u]=cnte;
}
int fa[MAXN],fw[MAXN][2];
int mx[MAXN],s[MAXN];
void Div(int x,int c){
	while(x>1){
		int p=pd[x];
		int k=0;
		while(x%p==0)
			k++,x/=p;
		s[p]+=k*c;
		mx[p]=max(mx[p],s[p]);
	}
	return ;
}
void Dfs1(int u){
	if(u>1) Div(fw[u][1],-1),Div(fw[u][0],1);
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		fw[v][0]=ww[i][0];
		fw[v][1]=ww[i][1];
		Dfs1(v);
	}
	if(u>1) Div(fw[u][0],-1),Div(fw[u][1],1);
	return ;
}
int ans;
void Dfs2(int u,int x){
	if(u>1)
		x=x*Fstpw(fw[u][0],mod-2)%mod*fw[u][1]%mod;
	ans=(ans+x)%mod;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		Dfs2(v,x);
	}
	return ;
}
int main(){
	n=2e5;
	for(int i=2; i<=n; i++){
		pd[i]=i;
		for(int j=2; j*j<=i; j++)
			if(i%j==0){
				pd[i]=j;
				break;
			}
	}
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		cnte=0;
		for(int i=1; i<=n; i++)
			h[i]=mx[i]=s[i]=0;
		for(int i=1; i<n; i++){
			int u,v,x,y;
			scanf("%d%d%d%d",&u,&v,&x,&y);
			adde(u,v,x,y);
			adde(v,u,y,x);
		}
		Dfs1(1);
		ans=0;
		int mul=1;
		for(int i=2; i<=n; i++)
			if(pd[i]==i) mul=mul*Fstpw(i,mx[i])%mod;
		Dfs2(1,mul);
		printf("%d\n",ans);
	}
	return 0;
}