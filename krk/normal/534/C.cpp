#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll A;
int d[Maxn];
ll sumd;

int main()
{
	scanf("%d %I64d", &n, &A);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]); sumd += d[i];
	}
	for (int i = 0; i < n; i++) {
		ll mn = max(1ll, A - sumd + d[i]);
		ll mx = min(ll(d[i]), A - (n - 1));
		printf("%I64d%c", ll(d[i]) - (mx - mn + 1), i + 1 < n? ' ': '\n');
	}
	return 0;
}