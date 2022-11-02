#include<bits/stdc++.h>
using namespace std;

const int maxn=5010;
int a[maxn];
int n;
int num1,num2;
int ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==1)	num1++;else num2++;
	}
	ans=max(num1,num2);
	for (int i=1;i<=n;i++)
	if (a[i]==2)
	{
		int l=i,r=i;
		int ha1=0,ha2=0;
		int tmp=0;
		for (int j=i+1;j<=n;j++)
		{
			if (a[j]==1)	tmp++;else tmp--;
			if (tmp>ha2)	r=j,ha2=tmp;
		}
		tmp=0;
		for (int j=i-1;j>=1;j--)
		{
			if (a[j]==2)	tmp++;else tmp--;
			if (tmp>ha1)	l=j,ha1=tmp;
		}
		int cnt=0;
		for (int j=1;j<l;j++)
			if (a[j]==1)	cnt++;
		for (int j=l;j<=i;j++)
			if (a[j]==2)	cnt++;
		for (int j=i+1;j<=r;j++)
			if (a[j]==1)	cnt++;
		for (int j=r+1;j<=n;j++)
			if (a[j]==2)	cnt++;
		if (cnt>ans)	ans=cnt;
	}
	printf("%d\n",ans);
	return 0;
}