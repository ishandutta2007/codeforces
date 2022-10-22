#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n, k;
ll b;
int a[Maxn];
set <ii> S;
ll tsum, obest;

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%I64d", &b);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i + 1 < n; i++)
		if (S.size() < k - 1) S.insert(ii(a[i], i));
		else if (!S.empty() && S.begin()->first < a[i]) { S.erase(S.begin()); S.insert(ii(a[i], i)); }
	for (int i = 0; i + 1 < n; i++)
		if (S.count(ii(a[i], i))) tsum += a[i];
		else obest = max(obest, ll(a[i]));
	int i;
	for (i = 0; i + 1 < n; i++)
		if (S.count(ii(a[i], i)) && tsum + obest > b || !S.count(ii(a[i], i)) && tsum + ll(a[i]) > b)
			break;
	printf("%d\n", i + 1);
	return 0;
}