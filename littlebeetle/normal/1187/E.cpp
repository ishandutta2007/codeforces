#include<cstdio>
const int N=400002;
typedef long long ll;
int n,k,i,j,a,b,h[N],t[N],v[N],sz[N];
ll ans,f[N];
void init(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
}
void dfs1(int i,int fa){
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs1(v[j],i);
			sz[i]+=sz[v[j]];
		}
	ans+=sz[i];
}
void dfs2(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			f[v[j]]=f[i]-sz[v[j]]+(n-sz[v[j]]);
			if(f[v[j]]>ans)
				ans=f[v[j]];
			dfs2(v[j],i);
		}
}
int main(){
	init();
	dfs1(1,0);
	f[1]=ans;
	dfs2(1,0);
	printf("%lld",ans);
}