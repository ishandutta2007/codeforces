#include<bits/stdc++.h>
using namespace std;
int n,m,a[1111],c[1111],pos,cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	pos=1;
	for (int i=1;i<=n;i++)
	{
		if (pos>m) break;
		if (a[pos]>=c[i]) 
		{
			pos++;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}