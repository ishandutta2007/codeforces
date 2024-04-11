#include<cstdio>
const int N=100002;
int n,n1,n2,a[N],x[N],y[N],idx[N],idy[N],i,j,k,h[N],t[N],v[N],w[N],S,T,q[N],s,e,g[N],l[N],d[N],F,H[N],To[N],V[N],vis[N],sum[N],ans;
bool f[N];
void prepare(){
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i;
		for(j=0;i*a[j]<N&&(!j||i%a[j-1]);j++)
			f[i*a[j]]=1;
	}
}
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
	if(!--g[d[i]])d[S]=T+1;
	++g[++d[i]];l[i]=h[i];
	return f;
}
void Dfs(int i){
	vis[i]=1;
	sum[k]++;
	for(int j=H[i];j;j=To[j])
		if(!vis[V[j]])
			Dfs(V[j]);
}
void DFS(int i){
	vis[i]=1;
	if(i<=n1+1)
		printf("%d ",idx[i-1]);
	else
		printf("%d ",idy[i-1-n1]);
	for(int j=H[i];j;j=To[j])
		if(!vis[V[j]])
			DFS(V[j]);
}
int main(){
	prepare();
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k&1)
			x[++n1]=k,idx[n1]=i;
		else
			y[++n2]=k,idy[n2]=i;
	}
	k=1;S=1;T=n+2;
	for(i=1;i<=n1;i++)
		add(S,1+i,2);
	for(i=1;i<=n2;i++)
		add(i+n1+1,T,2);
	for(i=1;i<=n1;i++)
		for(j=1;j<=n2;j++)
			if(!f[x[i]+y[j]])
				add(1+i,1+n1+j,1);
	for(i=1;i<=T;i++)
		l[i]=h[i];
	g[d[q[s=e=0]=T]=1]++;
	while(s<=e)
		for(j=h[i=q[s++]];j;j=t[j])
			if(!d[v[j]])
				g[d[v[j]]=d[i]+1]++,q[++e]=v[j];
	do
		F+=dfs(S,1<<30);
	while(d[S]<=T);
	if(F!=n){
		printf("Impossible");
		return 0;
	}
	k=0;
	for(i=2;i<=n1+1;i++)
		for(j=h[i];j;j=t[j])
			if(w[j]==0&&v[j]>1+n1&&v[j]<T){
				To[++k]=H[i];H[i]=k;V[k]=v[j];
				To[++k]=H[v[j]];H[v[j]]=k;V[k]=i;
			}
	for(k=2;k<=n+1;k++)
		if(!vis[k])
			Dfs(k),ans++;
	printf("%d\n",ans);
	for(k=2;k<=n+1;k++)
		vis[k]=0;
	for(k=2;k<=n+1;k++)
		if(!vis[k]){
			printf("%d ",sum[k]);
			DFS(k);
			printf("\n");
		}
}