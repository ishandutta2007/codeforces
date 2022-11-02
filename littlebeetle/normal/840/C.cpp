#include<cstdio>
#include<cmath>
using namespace std;
const int N=301,M=1000000007;
typedef long long ll;
int n,i,j,k,a[N],fa[N],sz[N],f[N][N][N],c[N*2][N*2];
int cnt,id,col[N],fis[N],o;
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
void merge(int x,int y){
	x=p(x);y=p(y);
	if(x==y)return;
	sz[x]+=sz[y];
	fa[y]=x;
}
bool ok(ll x){
	ll y=(ll)sqrt(x);
	return y*y==x||(y+1)*(y+1)==x;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),fa[i]=i,sz[i]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(ok(1ll*a[i]*a[j]))
				merge(i,j);
	for(i=0;i<N*2;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	}
}
void work(){
	for(i=1;i<=n;i++)
		if(p(i)==i){
			k=sz[i];
			id++;
			o=cnt+1;
			for(j=0;j<k;j++){
				col[++cnt]=id;
				fis[cnt]=o;
			}
		}
	f[0][0][0]=1;
	for(i=1;i<=n;i++){
		if(col[i]!=col[i-1]){
			for(j=0;j<=i;j++)
				for(k=0;j+k<=i;k++){
					f[i][j+k][0]=(f[i][j+k][0]+1ll*f[i-1][j][k]*(i-j-k))%M;
					if(j+k)
						f[i][j+k-1][0]=(f[i][j+k-1][0]+1ll*f[i-1][j][k]*(j+k))%M;
				}	
		}
		else{
			for(j=0;j<=fis[i];j++)
				for(k=0;k<=i-fis[i];k++){
					f[i][j][k+1]=(f[i][j][k+1]+1ll*f[i-1][j][k]*((i-fis[i])*2-k))%M;
					if(j)
						f[i][j-1][k]=(f[i][j-1][k]+1ll*f[i-1][j][k]*j)%M;
					f[i][j][k]=(f[i][j][k]+1ll*f[i-1][j][k]*(i-j-((i-fis[i])*2-k)))%M;															
				}
		}
	}
	printf("%d",f[n][0][0]);
}
int main(){
	init();
	work();
	return 0;
}