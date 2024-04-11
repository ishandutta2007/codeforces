#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m, k;
int place[Maxn], inplace[Maxn];
ll res;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &place[i]); inplace[place[i]] = i;
	}
	while (m--) {
		int id; scanf("%d", &id);
		int pl = inplace[id];
		res += 1 + (pl - 1) / k;
		if (pl != 1) { inplace[place[pl - 1]] = pl; inplace[place[pl]] = pl - 1; swap(place[pl - 1], place[pl]); }
	}
	printf("%I64d\n", res);
	return 0;
}