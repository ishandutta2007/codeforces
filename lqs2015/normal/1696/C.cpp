#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, k, a[55555], b[55555], x, c, tt, lst;
bool f;
long long nn;
vector<pair<int, long long> > v;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		v.clear();
		lst = -1; nn = 0;
		for (int i = 1; i <= n; i++)
		{
			x = a[i];
			while(x % m == 0) x /= m;
			if (x == lst) nn += (a[i] / x);
			else
			{
				if (~lst) v.push_back(make_pair(lst, nn));
				lst = x;
				nn = a[i] / x;
			}
		}
		if (nn) v.push_back(make_pair(lst, nn));
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) scanf("%d", &b[i]);
		reverse(v.begin(), v.end()); f = 0;
		for (int i = 1; i <= k; i++)
		{
			if (v.empty())
			{
				f = 1;
				break;
			}
			tt = v.back().first;
			if (b[i] % tt != 0)
			{
				f = 1;
				break;
			}
			x = b[i] / tt;
			if (v.back().second < x) 
			{
				f = 1;
				break;
			}
			while(x % m == 0) x /= m;
			if (x != 1)
			{
				f = 1;
				break;
			}
			v.back().second -= (b[i] / tt);
			if (v.back().second == 0) v.pop_back();
			/*for (int j = 0; j < v.size(); j++)
			{
				cout << v[j].first << " " << v[j].second << endl;
			}
			cout << endl;*/
		}
		if (!v.empty()) f = 1;
		if (f) printf("No\n");
		else printf("Yes\n");
    }
	return Accepted;
}