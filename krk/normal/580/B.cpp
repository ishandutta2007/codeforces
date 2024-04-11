#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n, d;
ii ms[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &ms[i].first, &ms[i].second);
	sort(ms, ms + n);
	ll cur = 0;
	int r = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && (l == r || ms[r].first - ms[l].first < d)) {
			cur += ms[r].second; r++;
		}
		res = max(res, cur);
		cur -= ms[l].second;
	}
	printf("%I64d\n", res);
	return 0;
}