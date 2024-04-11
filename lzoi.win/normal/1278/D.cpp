#include<cstdio>
const int MAXN=5e5+5;
int n;
int a[MAXN<<1],b[MAXN<<1];
int p[MAXN],vis[MAXN],pre[MAXN],suf[MAXN];
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
void Dfs(int u){
	if(vis[u]) return ;
	vis[u]=1;
	for(int i=h[u]; i; i=nx[i])
		Dfs(to[i]);
	return ;
}
bool Check(){
	for(int i=1;i<=n<<1;i++){
		//printf("p ");
		//for(int j=suf[0];j<=n;j=suf[j]) printf("%d ",p[j]);puts("");
		if(b[i]){
			p[++*p]=a[i];
			pre[*p]=pre[n+1];
			suf[*p]=n+1;
			suf[pre[n+1]]=*p;
			pre[n+1]=*p;
			continue;
		}
		if(p[pre[n+1]]==a[i]){
			int t=pre[n+1];
			pre[suf[t]]=pre[t];
			suf[pre[t]]=suf[t];
			continue;
		}
		for(int j=pre[n+1];p[j]!=a[i];j=pre[j]){
			adde(p[j],a[i]);
			adde(a[i],p[j]);
			//printf("adde %d %d j %d\n",p[j],a[i],j);
			if(cnte==n*2) return 0;
			if(p[pre[j]]==a[i]){
				j=pre[j];
				pre[suf[j]]=pre[j];
				suf[pre[j]]=suf[j];
				break;
			}
		}
	}
	if(cnte!=n*2-2) return 0;
	Dfs(1);
	for(int i=1; i<=n; i++)
		if(!vis[i]) return 0;
	return 1;
}
int main(){
	//freopen("D.in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int l,r;
		scanf("%d%d",&l,&r);
		a[l]=a[r]=i;
		b[l]=1;
	}
	suf[0]=n+1;
	if(Check()) puts("YES");
	else puts("NO");
	return 0;
}