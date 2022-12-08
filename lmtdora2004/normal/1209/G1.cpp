#include <bits/stdc++.h>

using namespace std;

int a[200005];
int cnt[200005];
int f[200005], l[200005];
signed main()
{
	int n, q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		l[a[i]]=i;
	}
	int ans=0;
	int lel=0;
	int clast=0, cclast=0;
	for(int i=1; i<=n; i++)
	{
		clast=max(clast, l[a[i]]);
		if(clast==i)
		{
//			cout<<i<<endl;
			lel=0;
			for(int j=cclast+1; j<=i; j++)
			{
				cnt[a[j]]++;
				lel=max(lel, cnt[a[j]]);
			}
			ans+=clast-cclast-lel;
			cclast=clast;
			for(int j=cclast+1; j<=i; j++)
			{
				cnt[a[j]]--;
//				lel=max(lel, cnt[a[i]]);
			}
		}
	}
	cout<<ans;
}