#include<cstdio>
const int N=402;
int n,m,i,j,k,a,b,p;
int val[N],h[N],t[N],v[N],f[N][N],sum;
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",val+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
}
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa)
			dfs(v[j],i);
	f[i][0]=val[i];
	for(a=h[i];a;a=t[a])
		if(v[a]!=fa){
			for(p=0;p<=m-1;p++){
				sum=f[v[a]][p];
				for(b=h[i];b;b=t[b])
					if(v[b]!=fa&&v[b]!=v[a])
						sum+=f[v[b]][max(m-1-p,p)];
				f[i][p+1]=max(f[i][p+1],sum);
			}
			f[i][0]+=f[v[a]][m];
		}
	for(p=m-1;p>=0;p--)
		f[i][p]=max(f[i][p],f[i][p+1]);
}
void work(){
	dfs(1,0);
	printf("%d",f[1][0]);
}
int main(){
	init();
	work();
	return 0;
}