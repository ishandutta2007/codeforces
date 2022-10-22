#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef long long ll;

const int Maxn = 200005;
const int Maxp = 447;
const int Maxm = 1000005;

int n, t;
int a[Maxn];
ll freq[Maxm];
iii lri[Maxn];
ll cur;
ll res[Maxn];

bool Less(const iii &a, const iii &b)
{
	if (a.first.first / Maxp != b.first.first / Maxp) return a.first.first / Maxp < b.first.first / Maxp;
	return a.first.second < b.first.second;
}

void Inc(int x)
{
	cur += (2ll * freq[x]++ + 1ll) * x;
}

void Dec(int x)
{
	cur -= (2ll * freq[x]-- - 1ll) * x;
}

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &lri[i].first.first, &lri[i].first.second); lri[i].second = i;
	}
	sort(lri, lri + t, Less);
	int lef = 0, rig = -1;
	for (int i = 0; i < t; i++) {
		while (lri[i].first.first < lef) Inc(a[--lef]);
		while (lef < lri[i].first.first) Dec(a[lef++]);
		while (rig < lri[i].first.second) Inc(a[++rig]);
		while (lri[i].first.second < rig) Dec(a[rig--]);
		res[lri[i].second] = cur;
	}
	for (int i = 0; i < t; i++)
		printf("%I64d\n", res[i]);
	return 0;
}