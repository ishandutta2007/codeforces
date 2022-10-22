#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[100010],b[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i;scanf("%d",&n);scanf("%s",a+1);scanf("%s",b+1);
		int ans=n+1,sa=0,sb=0,tp=0;
		for (i=1;i<=n;i++)
		{
			sa+=(a[i]=='1');
			sb+=(b[i]=='1');
			tp+=(a[i]!=b[i]);
		}
		if (sb==sa) ans=min(ans,tp);
		tp=n-tp;int lst=0;
		if (n-sa+1==sb)
		{
			for (i=1;i<=n;i++) if (a[i]=='1')
			{
				tp+=lst;
				if (a[i]==b[i]) tp--,lst=1;
				else lst=0;
				ans=min(ans,tp+1);
			}
		}
		if (ans!=n+1)printf("%d\n",ans);
		else puts("-1");
	}
}