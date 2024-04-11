#include<cstdio>
const int N=5002;
typedef long long ll;
int f[N][N];
int n,m,T,i,j,k,a,b,c,h[N],t[N],v[N],w[N],fr[N][N];
int min(int x,int y){
	return x<y?x:y;
}
int dfs(int x,int y){
	if(x==1)return y==1?0:T+1;
	if(y==0)return T+1;
	if(f[x][y]!=-1)return f[x][y];
	f[x][y]=T+1;
	for(int j=h[x];j;j=t[j]){
		if(dfs(v[j],y-1)+w[j]<f[x][y]){
			f[x][y]=dfs(v[j],y-1)+w[j];
			fr[x][y]=v[j];
		}
	}
	return f[x][y];
}
void D(int x,int y){
	if(x==0)return;
	D(fr[x][y],y-1);
	printf("%d ",x);
}
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=-1;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&b,&a,&c);
		t[++k]=h[a];h[a]=k;v[k]=b;w[k]=c;
	}
	for(i=n;i;i--){
		dfs(n,i);
		if(f[n][i]<=T){
			printf("%d\n",i);
			D(n,i);
			return 0;
		}
	}
}