#include<cstdio>
const int N=600002;
int n,m,i,j,k,a,b,h[N],t[N],v[N],s[N],tp,p[N],dfn[N],low[N],Ti,id,d[N];
int H[N],T[N],V[N];
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
void Tarjan(int i,int fa){
	dfn[i]=low[i]=++Ti;
	s[++tp]=i;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			if(dfn[v[j]])
				low[i]=min(low[i],dfn[v[j]]);
			else{
				Tarjan(v[j],i);
				low[i]=min(low[i],low[v[j]]);
			}
		}
	if(dfn[i]==low[i]){
		int k;id++;
		do{
			k=s[tp--];
			p[k]=id;
		}
		while(k!=i);
	}
}
void dfs(int i,int fa){
	for(int j=H[i];j;j=T[j])
		if(V[j]!=fa){
			d[V[j]]=d[i]+1;
			dfs(V[j],i);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	Tarjan(1,0);
	k=0;
	for(i=1;i<=n;i++)
		for(j=h[i];j;j=t[j])
			if(p[i]!=p[v[j]]){
				a=p[i];
				b=p[v[j]];
				T[++k]=H[a];H[a]=k;V[k]=b;
			}
	dfs(1,0);
	for(i=1,k=0;i<=n;i++)
		if(d[i]>d[k])
			k=i;
	d[k]=0;
	dfs(k,0);
	for(i=1,k=0;i<=n;i++)
		k=max(k,d[i]);
	printf("%d",k);
}