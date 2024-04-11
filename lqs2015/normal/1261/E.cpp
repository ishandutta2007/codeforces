#include<bits/stdc++.h>
using namespace std;
int n,a[1111],num[1111],arr[1111],cnt,cur,lst,pre[1111],nnum[1111];
bool f[1111][1111],flag[1111];
void add(int x)
{
	if (x) 
	{
		cur++;
		nnum[cur]=x;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cnt=1;num[1]=n+1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=cnt;j++)
		{
			pre[j]=pre[j-1]+num[j];
		}
		lst=a[i];
		memset(flag,0,sizeof(flag));
		memset(arr,0,sizeof(arr));
		for (int j=1;j<=cnt;j++)
		{
			if (num[j]!=1) 
			{
				flag[j]=1;
				arr[j]=min(lst,num[j]-1);
				lst-=arr[j];
				break;
			}
		}
		for (int j=1;j<=cnt;j++)
		{
			if (flag[j]) continue;
			arr[j]=min(num[j],lst);
			lst-=arr[j];
		}
		cur=0;
		for (int j=1;j<=cnt;j++)
		{
			add(num[j]-arr[j]);add(arr[j]);
			for (int k=pre[j-1]+num[j]-arr[j]+1;k<=pre[j];k++) f[k][i]=1;
		}
		cnt=cur;
		for (int j=1;j<=cnt;j++) num[j]=nnum[j];
	}
	printf("%d\n",n+1);
	for (int i=1;i<=n+1;i++)
	{
		for (int j=1;j<=n;j++)
		printf("%d",f[i][j]);
		printf("\n");
	}
	return 0;
}