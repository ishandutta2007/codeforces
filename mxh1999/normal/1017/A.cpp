#include<bits/stdc++.h>
using namespace std;

const int maxn=10010;
int n;
int a[maxn],b[maxn],c[maxn],d[maxn];
int id[maxn];
int x,y;
bool cmp(int x,int y)
{
	if (a[x]+b[x]+c[x]+d[x]!=a[y]+b[y]+c[y]+d[y])
		return a[x]+b[x]+c[x]+d[x]>a[y]+b[y]+c[y]+d[y];
	return x<y;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (id[i]==1)
		{
			printf("%d\n",i);
			return 0;
		}
	return 0;
}