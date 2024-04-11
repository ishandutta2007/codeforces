#include<cstdio>
const int N=600002;
int n,m,q,i,j,k,a,b,x,y,h[N],t[N],v[N],fa[N],len[N],dep[N],opt;
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
void dfs(int i,int f){
	if(dep[i]>dep[y])
		y=i;
	fa[i]=x;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=f){
			dep[v[j]]=dep[i]+1;
			dfs(v[j],i);
		}
}
int max(int x,int y){
	return x>y?x:y;
}
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		fa[i]=i;
	while(m--){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	for(i=1;i<=n;i++)
		if(!len[p(i)]){
			x=y=i;
			dfs(i,0);
			dep[y]=0;
			dfs(y,0);
			len[i]=dep[y];
		}
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			printf("%d\n",len[p(x)]);
		}
		else{
			scanf("%d%d",&x,&y);
			x=p(x);y=p(y);
			if(x!=y){
				len[y]=max(max(len[x],len[y]),(len[x]+1)/2+1+(len[y]+1)/2);
				fa[x]=y;
			}
		}
	}
}
int main(){
	init();
}