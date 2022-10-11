#include <iostream>
using namespace std;
double dp[105][105][105];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	dp[a][b][c]=1;
	for (int i=a;i>=0;i--)
	{
		for (int x=b;x>=0;x--)
		{
			for (int j=c;j>=0;j--)
			{
				double den=i*x+x*j+i*j,nom;
				if (den==0.0)
				continue;
				nom=i*x*dp[i][x][j];
				if (x)
				dp[i][x-1][j]+=nom/den;
				nom=x*j*dp[i][x][j];
				if (j)
				dp[i][x][j-1]+=nom/den;
				nom=i*j*dp[i][x][j];
				if (i)
				dp[i-1][x][j]+=nom/den;
			}
		}
	}
	double sumR=0.0,sumS=0.0,sumP=0.0;
	for (int i=1;i<=a;i++)
	sumR+=dp[i][0][0];
	for (int i=1;i<=b;i++)
	sumS+=dp[0][i][0];
	for (int i=1;i<=c;i++)
	sumP+=dp[0][0][i];
	printf("%.12lf %.12lf %.12lf",sumR,sumS,sumP);
}