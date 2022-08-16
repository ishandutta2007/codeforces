#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1010;

int x[MaxN],y[MaxN],sx[MaxN],sy[MaxN];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if ((n&1)!=(m&1))
	{
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;++i)
		sx[i]=1;
	for (int j=1;j<=m;++j)
		sy[j]=1;
	int get=(n-1)*(m-1)-k;
	while (k--)
	{
		int i,j,c;
		cin>>i>>j>>c;
		x[i]++;
		y[j]++;
		sx[i]*=c;
		sy[j]*=c;
	}
	for (int i=1;i<=n;++i)
		if (x[i]==m)
		{
			if (sx[i]!=-1)
			{
				puts("0");
				return 0;
			}
			++get;
		}
	for (int j=1;j<=m;++j)
		if (y[j]==n)
		{
			if (sy[j]!=-1)
			{
				puts("0");
				return 0;
			}
			++get;
		}
	int p;
	cin>>p;
	int ans=1;
	while (get--) (ans*=2)%=p;
	cout<<ans<<endl;
	return 0;
}