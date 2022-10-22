#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int n, r, avg;
ll need;
vector <ii> got;
ll res;

int main()
{
	scanf("%d %d %d", &n, &r, &avg);
	need = ll(n) * avg;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		need -= a;
		got.push_back(ii(b, r - a));
	}
	sort(got.begin(), got.end());
	for (int i = 0; i < got.size() && need > 0; i++) {
		ll tk = min(need, ll(got[i].second));
		res += tk * got[i].first; need -= tk;
	}
	printf("%I64d\n", res);
	return 0;
}