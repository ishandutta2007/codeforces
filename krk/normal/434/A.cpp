#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 9000000000000000000ll;

int n, m;
int a[Maxn];
vector <int> has[Maxn];
ll res;
ll best = Inf;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i + 1 < m; i++) if (a[i] != a[i + 1]) {
		has[a[i]].push_back(a[i + 1]);
		has[a[i + 1]].push_back(a[i]);
		res += abs(a[i] - a[i + 1]);
	}
	if (res == 0) { printf("0\n"); return 0; }
	for (int i = 1; i <= n; i++) if (!has[i].empty()) {
		sort(has[i].begin(), has[i].end());
		ll cur = res;
		for (int j = 0; j < has[i].size(); j++) {
			cur -= abs(has[i][j] - i);
			cur += has[i][j] - has[i][0];
		}
		best = min(best, cur);
		for (int j = 1; j < has[i].size(); j++) {
			int dec = has[i].size() - j;
			int inc = j;
			cur += ll(inc - dec) * (has[i][j] - has[i][j - 1]);
			best = min(best, cur);
		}
	}
	printf("%I64d\n", best);
	return 0;
}