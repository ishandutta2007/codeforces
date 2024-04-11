#include <bits/stdc++.h>
using namespace std;
int n, k, num[555], nw, x, lst, ans;
set<pair<int, int> > s;
vector<int> cur;
int main()
{
	scanf("%d%d", &n, &k);
	if ((n & 1) && (k % 2 == 0))
	{
		printf("-1\n");
		fflush(stdout);
		return 0;
	}
	for (int i = 1; i <= n; i++) num[i] = 1;
	nw = n; x = 1;
	while((nw % k) || num[1] > (nw / k))
	{
		nw += 2;
		num[x] += 2;
		x = x % n + 1;
	}
	for (int i = 1; i <= n; i++) s.insert(make_pair(-num[i], i));
	for (int i = 1; i <= nw / k; i++)
	{
		printf("? "); cur.clear();
		for (int j = 1; j <= k; j++)
		{
			cur.push_back(s.begin() -> second);
			s.erase(s.begin());
		}
		for (int j = 0; j < cur.size(); j++)
		{
			printf("%d ", cur[j]);
			num[cur[j]] --;
			s.insert(make_pair(-num[cur[j]], cur[j]));
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &x);
		ans ^= x;
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}