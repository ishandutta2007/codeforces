#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Inf = 1000000000;
const int Maxn = 2005;

int n, k;
int a[Maxn];
ii has[Maxn];
int res;

bool Check(int h)
{
	for (int i = 0; i < n; i++)
		has[i] = ii(ll(i) * ll(h) - ll(a[i]), ll(i) * ll(h) + ll(a[i]));
	sort(has, has + n);
	vector <ll> seq;
	for (int i = 0; i < n; i++) {
		int ind = upper_bound(seq.begin(), seq.end(), has[i].second) - seq.begin();
		if (ind == seq.size()) seq.push_back(has[i].second);
		else seq[ind] = has[i].second;
	}
	return seq.size() >= n - k;
}

int main()
{
	scanf("%d %d", &n, &k);
	if (n <= 1 || abs(n - k) <= 1) { printf("0\n"); return 0; }
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ll l = 0, r = 2 * Inf;
	while (l <= r) {
		int m = int(l + r >> 1ll);
		if (Check(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%d\n", res);
	return 0;
}