#include<bits/stdc++.h>
using namespace std;
int test,n;
long long a[111111],cur,l[111111],r[111111],cr;
bool flg;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		cur=1;
		for (int i=0;i<=40;i++)
		{
			for (int j=1;j<=n;j++) 
			{
				l[j]=a[j];
				r[j]=a[j]+cur-1;
			}
			flg=0;cr=-1e18;
			for (int j=1;j<=n;j++)
			{
				if (cr>r[j])
				{
					flg=1;
					break;
				}
				cr=max(cr,l[j]);
			}
			if (!flg)
			{
				printf("%d\n",i);
				break;
			}
			cur*=2;
		}
	}
	return 0;
}