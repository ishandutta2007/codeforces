#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> lli;

const int Maxn = 200005;

int n, m, k, s;
ii a[Maxn], b[Maxn];
vector <lli> V[2];

ll Get(const vector <lli> &V, int num)
{
	return num? V[num - 1].first: 0;
}

int Get(int day)
{
	int A = a[day].first, B = b[day].first;
	for (int i = 0; i <= k && i <= V[0].size(); i++) {
		int j = k - i;
		if (0 <= j && j <= V[1].size())
			if (ll(A) * Get(V[0], i) + ll(B) * Get(V[1], j) <= s)
				return i;
	}
	return -1;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		if (i == 1 || t < a[i - 1].first) a[i] = ii(t, i);
		else a[i] = a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		if (i == 1 || t < b[i - 1].first) b[i] = ii(t, i);
		else b[i] = b[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int t, c; scanf("%d %d", &t, &c);
		V[t - 1].push_back(lli(c, i));
	}
	for (int i = 0; i < 2; i++) {
		sort(V[i].begin(), V[i].end());
		for (int j = 1; j < V[i].size(); j++)
			V[i][j].first += V[i][j - 1].first;
	}
	int lef = 1, rig = n;
	int res = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Get(mid) != -1) { res = mid; rig = mid - 1; }
		else lef = mid + 1;
	} 
	if (res == -1) printf("-1\n");
	else {
		int x = Get(res);
		int y = k - x;
		printf("%d\n", res);
		for (int i = 0; i < x; i++)
			printf("%d %d\n", V[0][i].second, a[res].second);
		for (int i = 0; i < y; i++)
			printf("%d %d\n", V[1][i].second, b[res].second);
	}
	return 0;
}