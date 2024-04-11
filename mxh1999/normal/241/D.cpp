#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
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

#define maxn 50010
int a[maxn],b[maxn];
int n,m;
int f[33][32][maxn];
//int xx[33][32][maxn],yy[33][32][maxn];
int mjy,xmm[33];
int p;
int main()
{
	read(n),read(p);
	for (int i=1;i<=n;i++)
	{
		int x;
		read(x);
		if (x<32)	{a[++m]=x;b[m]=i;}
	}
	f[m][0][0]=1;
	for (int i=m-1;i>=0;i--)
	{
		for (int j=0;j<32;j++)
			for (int k=0;k<p;k++)
			{
				if (f[i][j][k]<f[i+1][j][k])	f[i][j][k]=f[i+1][j][k];
				int num=k;
				if (a[i+1]>=10)	num=(num*10+a[i+1]/10)%p;
				num=(num*10+a[i+1]%10)%p;
				if (f[i+1][j^a[i+1]][num])
				if (f[i][j][k]<f[i+1][j^a[i+1]][num]+1)	f[i][j][k]=f[i+1][j^a[i+1]][num]+1;
			}
	}
	if (f[0][0][0]>1)
	{
		printf("Yes\n");
		int j=0,k=0;
		for (int i=1;i<=m;i++)
		{
			if (f[i][j][k] && f[i][j][k]==f[i-1][j][k])	continue;
			int num=k;
			if (a[i]>=10)	num=(num*10+a[i]/10)%p;
			num=(num*10+a[i]%10)%p;
			if (f[i][j^a[i]][num]==f[i-1][j][k]-1)	j=j^a[i],k=num,xmm[++mjy]=b[i];
		}
		printf("%d\n",mjy);
		for (int i=1;i<=mjy;i++)	printf("%d ",xmm[i]);
		printf("\n");
		//cerr<<mxh<<endl;
	}	else	printf("No\n");
	return 0;
}