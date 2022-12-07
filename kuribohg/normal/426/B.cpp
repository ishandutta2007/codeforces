#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,a[110][110],ans,r;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	r=n;
	while(!(r&1))
	{
		r>>=1;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]!=a[(r<<1|1)-i][j]) goto p;
		ans++;
	}
p:	for(int i=1;i<=ans;i++) n>>=1;
	printf("%d\n",n);
	return 0;
}