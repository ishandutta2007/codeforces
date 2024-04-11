#include<cstdio>
#include<algorithm>
using namespace std;
const int N=400002,K=20;

struct p{
	int x,y,z;
	bool operator<(const p &k)const{
		return k.z>z;
	}
}e[N];
int n,m,i,j,k,x[N],y[N],z[N],a,b,c,fa[N];
int h[N],t[N],v[N],w[N],dep[N],f[N][K],g[N][K];
long long sum;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",x+i,y+i,z+i);
		e[i]=(p){x[i],y[i],z[i]};
	}
}
int F(int x){
	return x==fa[x]?x:fa[x]=F(fa[x]);
}
void add(int a,int b,int c){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
	w[k]=c;
}
void kurskal(){
	sort(e+1,e+m+1);
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++){
		a=e[i].x;b=e[i].y;
		a=F(a);b=F(b);
		if(a!=b){
			fa[a]=b;
			add(a,b,e[i].z);
			add(b,a,e[i].z);
			sum+=e[i].z;
		}
	}
	//printf("%lld",sum);
}
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i,int Fa){
	int j;
	for(j=0;(1<<j+1)<=dep[i];j++){
		f[i][j+1]=f[f[i][j]][j];
		g[i][j+1]=max(g[i][j],g[f[i][j]][j]);
	}
	for(int j=h[i];j;j=t[j])
		if(v[j]!=Fa){
			dep[v[j]]=dep[i]+1;
			f[v[j]][0]=i;
			g[v[j]][0]=w[j];
			dfs(v[j],i);
		}
}
int Get(int a,int b){
	int s=0;
	if(dep[a]<dep[b])
		k=a,a=b,b=k;
	j=dep[a]-dep[b];
	for(k=0;k<=20;k++)
		if(j>>k&1){
			s=max(s,g[a][k]);
			a=f[a][k];
			j-=1<<k;
		}
	return s;
}
int LCA(int a,int b){
	if(dep[a]<dep[b])
		k=a,a=b,b=k;
	j=dep[a]-dep[b];
	for(k=0;k<=20;k++)
		if(j>>k&1){
			a=f[a][k];
			j-=1<<k;
	}
	if(a==b)return a;
	for(k=18;k>=0;k--)
		if(f[a][k]!=f[b][k])
			a=f[a][k],b=f[b][k];
	return f[a][0];
}
int DDD(int a,int b){
	int c=LCA(a,b);
	return max(Get(a,c),Get(b,c));
}
void work(){
	for(i=1;i<=m;i++)
		printf("%lld\n",sum+z[i]-DDD(x[i],y[i]));
	//while(1);
}
int main(){
	init();
	kurskal();
	dfs(1,0);
	work();
}