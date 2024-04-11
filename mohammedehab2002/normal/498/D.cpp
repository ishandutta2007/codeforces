#include <bits/stdc++.h>
using namespace std;
#define BU 40
int n,a[100005],cnt[100005][60];
void upd(int x)
{
	for (int i=59;i>=0;i--)
	cnt[x][i]=1+(i%a[x]==0);
	x--;
	while ((x+1)%BU!=0)
	{
		for (int i=59;i>=0;i--)
		cnt[x][i]=1+cnt[x+(i%a[x]!=0)][(i+1)%60];
		x--;
	}
}
int main()
{
	int q;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if (i==n-1 || (i+1)%BU==0)
		upd(i);
	}
	scanf("%d",&q);
	while (q--)
	{
		char t;
		int l,r;
		scanf(" %c%d%d",&t,&l,&r);
		l--;
		if (t=='C')
		{
			a[l]=r;
			upd(min(l-l%BU+BU,n)-1);
		}
		else
		{
			r--;
			int ct=0;
			while (1)
			{
				int nex=l-l%BU+BU;
				if (nex>=r)
				break;
				ct+=cnt[l][ct%60];
				l=nex;
			}
			while (l!=r)
			{
				if (ct%a[l])
				l++;
				ct++;
			}
			printf("%d\n",ct);
		}
	}
}