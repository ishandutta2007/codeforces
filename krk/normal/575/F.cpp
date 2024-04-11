#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10005;
const ll Inf = 1000000000000000000ll;

int n;
int a[Maxn], b[Maxn];
vector <int> seq;
ll dp[2][Maxn];
int cur;

int Dist(int x, int a, int b)
{
	if (x <= a) return a - x;
	if (b <= x) return x - b;
	return 0;
}

int main()
{
	int x;
	scanf("%d %d", &n, &x);
	seq.push_back(x);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		seq.push_back(a[i]); seq.push_back(b[i]);
	}
	sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
	for (int i = 0; i < seq.size(); i++)
		dp[cur][i] = x == seq[i]? 0: Inf;
	for (int i = 0; i < n; i++) {
		fill(dp[!cur], dp[!cur] + seq.size(), Inf);
		ll best = Inf;
		int lst = 0;
		for (int j = 0; j < seq.size(); j++) {
			best = min(best + seq[j] - lst, dp[cur][j]);
			dp[!cur][j] = best;
			lst = seq[j];
		}
		best = Inf;
		lst = 1000000000;
		for (int j = int(seq.size()) - 1; j >= 0; j--) {
			best = min(best + lst - seq[j], dp[cur][j]);
			dp[!cur][j] = min(dp[!cur][j], best) + Dist(seq[j], a[i], b[i]);
			lst = seq[j];
		}
		cur = !cur;
	}
	ll best = Inf;
	for (int j = 0; j < seq.size(); j++)
		best = min(best, dp[cur][j]);
	printf("%I64d\n", best);
	return 0;
}