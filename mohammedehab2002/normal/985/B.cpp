#include <iostream>
using namespace std;
int cnt[2005];
char arr[2005][2005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	for (int i=0;i<n;i++)
	{
		gets(arr[i]);
		for (int x=0;x<m;x++)
		cnt[x]+=arr[i][x]-'0';
	}
	for (int i=0;i<n;i++)
	{
		bool ok=1;
		for (int x=0;x<m;x++)
		{
			cnt[x]-=arr[i][x]-'0';
			if (!cnt[x])
			ok=0;
		}
		if (ok)
		{
			printf("YES");
			return 0;
		}
		for (int x=0;x<m;x++)
		cnt[x]+=arr[i][x]-'0';
	}
	printf("NO");
}