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

#define maxn 2010
double C[maxn][maxn],all;
int b[maxn][maxn];
int du[maxn];
int n,k;
double mjy;
const double eps=1e-9;
int main()
{
	read(n),read(k);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int x;
			read(x);
			b[i][j]=b[j][i]=x;
			if (x>-1)	du[i]++,du[j]++;
		}
	for (int i=1;i<=n;i++)	b[i][i]=-1;
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)	C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for (int i=1;i<=n;i++)
	if (du[i]>=k)	all+=C[du[i]][k];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (b[i][j]!=-1)
			mjy+=C[du[i]-1][k-1]*b[i][j];
	mjy/=all;
	ll mmdmjy=(ll)(mjy+eps);
	printf("%I64d\n",mmdmjy);
	return 0;
}