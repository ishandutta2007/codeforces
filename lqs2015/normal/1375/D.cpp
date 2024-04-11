#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[1111],cnt,ans[2222],c;
bool used[1111];
bool check()
{
	for (int i=1;i<n;i++)
	{
		if (a[i]>a[i+1]) return 0;
	}
	return 1;
}
int calm()
{
	for (int i=0;i<=n;i++) used[i]=0;
	for (int i=1;i<=n;i++) used[a[i]]=1;
	int pos=0;
	while(used[pos]) pos++;
	return pos;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		cnt=0;
		while(1)
		{
			if (check()) break;
			c=calm();++cnt;
			if (c==n)
			{
				for (int i=1;i<=n;i++)
				{
					if (a[i]!=i-1) 
					{
						ans[cnt]=i;
						break;
					}
				}
			}
			else ans[cnt]=c+1;
			a[ans[cnt]]=c;
		}
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return Accepted;
}