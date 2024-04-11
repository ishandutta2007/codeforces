#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

const int mo=1000000007;
#define maxn 160
ll f[maxn][maxn][maxn][4];
ll sum[maxn][maxn][maxn][4];
ll mjy;
int n,m;
int main()
{
	read(n),read(m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			for (int k=j;k<=m;k++)
			{
				f[i][j][k][0]=(sum[i-1][m][k][0]-sum[i-1][j-1][k][0]+mo+1)%mo;
				f[i][j][k][1]=((sum[i-1][k][m][0]-sum[i-1][j-1][m][0]-sum[i-1][k][k][0]+sum[i-1][j-1][k][0]+
								sum[i-1][k][m][1]-sum[i-1][j-1][m][1]-sum[i-1][k][k-1][1]+sum[i-1][j-1][k-1][1])%mo+mo)%mo;
				f[i][j][k][2]=((sum[i-1][j-1][k][0]-sum[i-1][j-1][j-1][0]+sum[i-1][j][k][2]-sum[i-1][j][j-1][2])%mo+mo)%mo;
				f[i][j][k][3]=((sum[i-1][j-1][m][0]-sum[i-1][j-1][k][0]+sum[i-1][j-1][m][1]-sum[i-1][j-1][k-1][1]+sum[i-1][j][m][2]-sum[i-1][j][k][2]+sum[i-1][j][m][3]-sum[i-1][j][k-1][3])%mo+mo)%mo;
			}
		for (int j=1;j<=m;j++)
			for (int k=j;k<=m;k++)
				for (int _=0;_<4;_++)
					mjy=(mjy+f[i][j][k][_])%mo;
		for (int _=0;_<4;_++)
			for (int j=1;j<=m;j++)
				for (int k=1;k<=m;k++)
				sum[i][j][k][_]=((sum[i][j-1][k][_]+sum[i][j][k-1][_]-sum[i][j-1][k-1][_]+f[i][j][k][_])%mo+mo)%mo;
	}
	cout<<mjy<<endl;
	return 0;
}