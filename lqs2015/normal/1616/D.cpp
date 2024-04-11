#include <bits/stdc++.h>
using namespace std;
int test, n, res, pos;
int a[55555], x;
long long pre[55555];
pair<long long, int> arr[55555];
set<int> s;
set<int>::iterator it;
multiset<int> ss;
vector<pair<int, int> > vs;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		pre[0] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		scanf("%d", &x);
		for (int i = 1; i <= n; i++) a[i] -= x;
		pre[0] = 0;
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
		for (int i = 0; i <= n; i++) arr[i] = make_pair(pre[i], i);
		sort(arr, arr + n + 1); s.clear(); vs.clear();
		s.insert(arr[0].second);
		for (int i = 1; i <= n; i++)
		{
			it = s.lower_bound(arr[i].second + 2);
			if (it != s.end())
			{
				vs.push_back(make_pair(arr[i].second + 1, *it));
			}
			s.insert(arr[i].second);
		}
		sort(vs.begin(), vs.end());
		ss.clear(); res = 0; pos = 0;
		for (int i = 0; i < vs.size(); i++) ss.insert(vs[i].second);
		while(!ss.empty())
		{
			x = *ss.begin();
			while(pos < vs.size() && vs[pos].first <= x)
			{
				ss.erase(ss.find(vs[pos].second));
				pos ++;
			}
			res++;
		}
		printf("%d\n", n - res);
	}
	return 0;
}