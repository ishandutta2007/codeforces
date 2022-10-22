#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxm = 3005;

int n, m;
vector <int> prices[Maxm];
ll res = Inf;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int p, c; scanf("%d %d", &p, &c);
		prices[p].push_back(c);
	}
	for (int i = 1; i <= m; i++)
		sort(prices[i].rbegin(), prices[i].rend());
	for (int i = 1; i <= n; i++) {
		int col = 0;
		ll cand = 0;
		priority_queue <int> Q;
		for (int j = 2; j <= m; j++)
			for (int l = 0; l < prices[j].size(); l++)
				if (l + 1 >= i) { col++; cand += prices[j][l]; }
				else Q.push(-prices[j][l]);
		while (prices[1].size() + col < i) {
			col++; cand += -Q.top(); Q.pop();
		}
		res = min(res, cand);
	}
	cout << res << endl;
	return 0;
}