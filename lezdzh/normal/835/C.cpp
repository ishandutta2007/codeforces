#include<cstdio>

using namespace std;

int n,q,c;
int a[11][101][101];
int x[100001],y[100001],z[100001];
int main(){
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	c++;
	for(int i=0;i<c;i++)
		for(int j=1;j<=n;j++)
			a[i][x[j]][y[j]]+=(z[j]+i)%c;
	
	for(int w=0;w<c;w++)
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				a[w][i][j]+=a[w][i][j-1]+a[w][i-1][j]-a[w][i-1][j-1];
	for(;q--;){
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		t%=c;
		printf("%d\n",a[t][x2][y2]-a[t][x1-1][y2]-a[t][x2][y1-1]+a[t][x1-1][y1-1]);
	}
}