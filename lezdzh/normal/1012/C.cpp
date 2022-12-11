#include<cstdio>
#include<algorithm>
using namespace std;

int a[5001];
long long f[5001][2501][3];
void gx(long long&x,long long y){
	x=min(x,y);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long inf=~0ull>>1;
	for(int i=0;i<=n;i++)
		for(int j=0;j*2<=n+1;j++)
			f[i][j][0]=f[i][j][1]=f[i][j][2]=inf;
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j*2<=n+1;j++){
			if(f[i][j][0]!=inf){
				gx(f[i+1][j][0],f[i][j][0]);
				gx(f[i+1][j+1][2],f[i][j][0]+max(0,a[i]-a[i+1]+1));
			}
			if(f[i][j][1]!=inf){
				gx(f[i+1][j][0],f[i][j][1]);
				gx(f[i+1][j+1][2],f[i][j][1]+max(0,min(a[i],a[i-1]-1)-a[i+1]+1));
			}
			if(f[i][j][2]!=inf)
				gx(f[i+1][j][1],f[i][j][2]+max(0,a[i+1]-a[i]+1));
		}
	for(int i=1;i*2<=n+1;i++)
		printf("%I64d%c",min(min(f[n][i][0],f[n][i][1]),f[n][i][2]),(i+1)*2>n+1?'\n':' ');
}