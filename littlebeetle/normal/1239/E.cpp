#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
const int N=26,M=50*50000+2;
bitset<M>f[N*2][N];
int n,v,i,j,k,w[N*2],sum,Ans=1<<30,u,o;
bool g[N*2];
void init(){
	scanf("%d",&n);
	for(i=0;i<n*2;i++)
		scanf("%d",w+i),v+=w[i];
	sort(w,w+n*2);
}
int max(int x,int y){
	return x>y?x:y;
}
void Gt(int i,int k,int j){
	if(i==n*2)return;
	if(k>0&&j>=w[i]&&f[i+1][k-1][j-w[i]])
		g[i]=1,Gt(i+1,k-1,j-w[i]);
	else
		Gt(i+1,k,j);
}
void work(){
	f[n*2][0][0]=1;
	for(i=n*2-1;i;i--){
		for(j=1;j<=n&&j<=n*2-i;j++)
			f[i][j]|=f[i+1][j-1]<<w[i];
		if(n*2-i>=n){
			for(j=0;j<=v;j++)
				if(f[i][n][j]){
					sum=max(j+w[0],v-j+w[i]);
					if(sum<Ans)
						Ans=sum,u=i,o=j;
				}
		}
		for(j=0;j<=n&&j<=n*2-i;j++)
			f[i][j]|=f[i+1][j];
	}
	Gt(u,n,o);	
	for(i=0;i<n*2;i++)
		if(g[i])
			printf("%d ",w[i]);
	printf("\n");
	for(i=n*2-1;i>=0;i--)
		if(g[i]==0)
			printf("%d ",w[i]);
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}