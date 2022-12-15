#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 222222
int n;
vector<pair<LL,LL>> p;
pair<LL,LL> s[N];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		LL x, y;
		scanf("%lld%lld", &x, &y);
		y -= x * x;
		p.push_back(make_pair(x, y));
	}
	sort(p.begin(), p.end());
	int top = 0;
	for (int i = 0; i < n; i++)
	{
		LL x = p[i].first, y = p[i].second;
		while (top > 0)
		{
			if (s[top - 1].first == x) --top;
			else if (top >= 2)
			{
				LL x1 = s[top - 1].first, y1 = s[top - 1].second;
				LL x2 = s[top - 2].first, y2 = s[top - 2].second;
				if ((x1 - x2) * (y - y2) - (x - x2) * (y1 - y2) >= 0)
					--top;
				else
					break;
			}
			else
				break;
		}
		s[top]=make_pair(x,y);
		top+=1;
	}
	int ans=0;
	for (int i=0;i<top-1;i++)
		ans+=s[i].first!=s[i+1].first;
	printf("%d\n",ans);
}