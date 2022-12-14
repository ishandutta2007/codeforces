#include<bits/stdc++.h>
using namespace std;
int n,a[111],b[111],cnt,ans;
char s[111];
bool f[111];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for (int i=1;i<=n;i++) f[i]=(s[i-1]-'0');
	for (int i=1;i<=n;i++) cnt+=f[i];
	ans=cnt;
	for (int i=1;i<=100000;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if ((i-b[j])%a[j] || i<b[j]);
			else
			{
				if (f[j]) cnt--;
				else cnt++;
				f[j]=!f[j];
			}
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}