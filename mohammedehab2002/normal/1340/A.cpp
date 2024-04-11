#include <bits/stdc++.h>
using namespace std;
int p[100005],inv[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		set<int> s;
		multiset<int,greater<int> > cnt;
		s.insert(0);
		s.insert(n+1);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			inv[p[i]]=i;
			s.insert(i);
			cnt.insert(1);
		}
		bool ok=1;
		for (int i=1;i<=n;i++)
		{
			int cur=inv[i],pre=*prev(s.find(cur)),nex=*next(s.find(cur));
			ok&=((cur-pre)==*cnt.begin());
			cnt.erase(cnt.find(cur-pre));
			if (nex!=n+1)
			{
				cnt.erase(cnt.find(nex-cur));
				cnt.insert(nex-pre);
			}
			s.erase(s.find(cur));
		}
		puts(ok? "Yes":"No");
	}
}