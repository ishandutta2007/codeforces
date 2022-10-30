#include<bits/stdc++.h>
using namespace std;
int n,m,c0,d0,a,b,c,d,f[1005];
int main()
{
	scanf("%d%d%d%d",&n,&m,&c0,&d0);
	for(int i=1;i<=n;i++) f[i]=i/c0*d0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int j=1;j<=a/b;j++) for(int k=n;k>=c;k--) f[k]=max(f[k-c]+d,f[k]);
	}
	return printf("%d\n",f[n]),0;
}