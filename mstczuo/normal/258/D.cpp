# include <iostream>
# include <cstdio>
using namespace std;
int n,m,x,y,a[1001];
double F[1001][1001],ans;
void Mix(double &a, double &b)
{
	a=b=(a+b)/2;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			F[i][j]=a[i]>a[j],F[j][i]=1-F[i][j];
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		Mix(F[x][y],F[y][x]);
		for(int i=1;i<=n;i++)
			if(i-x&&i-y)Mix(F[i][x],F[i][y]),Mix(F[x][i],F[y][i]);
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=F[i][j];
	printf("%.8lf",ans);
}