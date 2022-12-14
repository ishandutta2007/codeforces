#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,pos,cnt,xx[333333],yy[333333];
long long zz[333333];
long long a[111111];
int nxt(int x)
{
	while(x<=n && a[x]>=0) x++;
	return x; 
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x]+=z;a[y]-=z;
	}
	pos=nxt(1);
	for (int i=1;i<=n;i++)
	{
		while(a[i]>0)
		{
			if (-a[pos]<=a[i])
			{
				++cnt;xx[cnt]=i;yy[cnt]=pos;zz[cnt]=-a[pos];
				a[i]+=a[pos];
				a[pos]=0;pos=nxt(pos);
			}
			else
			{
				++cnt;xx[cnt]=i;yy[cnt]=pos;zz[cnt]=a[i];
				a[pos]+=a[i];a[i]=0;
			}
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) 
	{
		printf("%d %d %lld\n",xx[i],yy[i],zz[i]);
	}
	return 0;
}