#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

int n;
ii x[Maxn];
int k;
ll L[Maxn], R[Maxn];
ll cur;
ll best;
int from;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i].first); x[i].second = i + 1;
	}
	sort(x, x + n);
	scanf("%d", &k);
	for (int i = 1; i < n; i++)
		L[i] = L[i - 1] + ll(i) * ll(x[i].first - x[i - 1].first);
	for (int i = n - 2; i >= 0; i--)
		R[i] = R[i + 1] + ll(n - 1 - i) * ll(x[i + 1].first - x[i].first);
	for (int i = 0; i < k; i++)
		cur += L[i];
	best = cur; from = 0;
	for (int i = k; i < n; i++) {
		cur -= R[i - k] - ll(n - i) * ll(x[i - 1].first - x[i - k].first) - R[i - 1];
		cur += L[i] - ll(i - k + 1) * ll(x[i].first - x[i - k + 1].first) - L[i - k + 1];
		if (cur < best) { best = cur; from = i - k + 1; }
	}
	for (int i = 0; i < k; i++)
		printf("%d%c", x[from + i].second, i + 1 < k? ' ': '\n');
	return 0;
}