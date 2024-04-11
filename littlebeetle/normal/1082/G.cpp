#include<cstdio>
const int N=300002;
int n,m,S,T,a[N],i,j,k,x[N],y[N],c[N],h[N],t[N],v[N],w[N],d[N],g[N],l[N],q[N],s,e;
long long sum,ans;
void add(int a,int b,int c){
	t[++k]=h[a];h[a]=k;v[k]=b;w[k]=c;
	t[++k]=h[b];h[b]=k;v[k]=a;w[k]=0;
}
int min(int x,int y){
	return x<y?x:y;
}
int dfs(int i,int p){
	if(i==T)return p;
	int f=0;
	for(int &j=l[i],x;j;j=t[j])
		if(d[i]==d[v[j]]+1&&w[j]){
			x=dfs(v[j],min(p,w[j]));
			if(x){
				w[j]-=x;w[j^1]+=x;
				p-=x;f+=x;
			}
			if(!p)return f;
		}
	if(!--g[d[i]])d[S]=T;
	++g[++d[i]];l[i]=h[i];
	return f;
}
int main(){
	scanf("%d%d",&n,&m);
	S=1;T=1+n+m+1;k=1;
	for(i=1;i<=n;i++)
		scanf("%d",a+i),add(1+m+i,T,a[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",x+i,y+i,c+i);
		sum+=c[i];
		add(S,1+i,c[i]);
		add(1+i,1+m+x[i],1<<30);
		add(1+i,1+m+y[i],1<<30);
	}
	for(i=1;i<=T;i++)
		l[i]=h[i];
	g[d[q[s=e=0]=T]=1]++;
	while(s<=e)
		for(j=h[i=q[s++]];j;j=t[j])
			if(!d[v[j]])
				g[d[v[j]]=d[i]+1]++,q[++e]=v[j];
	do ans+=dfs(S,1<<30);
	while(d[S]<T);		
	printf("%lld",sum-ans);
	return 0;
}