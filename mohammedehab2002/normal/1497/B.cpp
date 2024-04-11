#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		cnt[i]=0;
		while (n--)
		{
			int a;
			scanf("%d",&a);
			cnt[a%m]++;
		}
		int ans=min(cnt[0],1);
		for (int i=1;i<(m+1)/2;i++)
		{
			if (!cnt[i] && !cnt[m-i])
			continue;
			ans++;
			if (cnt[i]!=cnt[m-i])
			ans+=abs(cnt[i]-cnt[m-i])-1;
		}
		if (m%2==0 && cnt[m/2])
		ans++;
		printf("%d\n",ans);
	}
}