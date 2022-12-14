#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[1111],cnt,id;
pair<int,int> ans[1111111];
pair<int,int> arr[1111];
bool used[1111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) arr[i]=make_pair(a[i],i);
	sort(arr+1,arr+n+1);
	for (int i=1;i<=n;i++)
	{
		id=arr[i].second;
		for (int j=n;j>id;j--)
		{
			if (used[j]) 
			{
				ans[++cnt]=make_pair(id,j);
			}
		}
		used[id]=1;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return Accepted;
}