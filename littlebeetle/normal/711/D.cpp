#include<cstdio>
const int N=200002,M=1000000007;
int n,i,j,k,fa[N],deg[N],cnt;
int q[N],s,e,vis[N];
long long Ans=1,p;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",fa+i);
		deg[fa[i]]++;
	}
}
void dfs(int i){
	vis[i]=1;
	cnt++;
	if(!vis[fa[i]])
		dfs(fa[i]);
}
void work(){
	s=1;
	for(i=1;i<=n;i++)
		if(deg[i]==0)
			q[++e]=i;
	while(s<=e){
		i=q[s++];
		vis[i]=1;
		deg[fa[i]]--;
		if(deg[fa[i]]==0)
			q[++e]=fa[i];
	}
	while(e--)
		Ans=Ans*2%M;
	for(i=1;i<=n;i++)
		if(vis[i]==0){
			cnt=0;
			dfs(i);
			p=1;
			while(cnt--)
				p=p*2%M;
			Ans=Ans*(p-2+M)%M;
		}
	printf("%lld",Ans);
}
int main(){
	init();
	work();
	return 0;
}