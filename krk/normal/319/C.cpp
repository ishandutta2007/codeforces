#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];
ll dp[Maxn];
set <int> S;
set <ii> E;

void Add(int ind)
{
	if (!S.empty()) {
		ll a = (dp[ind] - dp[*S.rbegin()]) / ll(b[*S.rbegin()] - b[ind]);
		if (a * ll(b[*S.rbegin()] - b[ind]) < dp[ind] - dp[*S.rbegin()]) a++;
		E.insert(ii(a, ind));
	}
	S.insert(ind);
}

ll Get(ll a)
{
	while (!E.empty() && E.begin()->first <= a) {
		ii todel = *E.begin(); E.erase(E.begin());
		set <int>::iterator it = S.lower_bound(todel.second);
		if (it == S.end() || *it != todel.second) continue;
		it--; S.erase(it++);
		if (it != S.begin()) {
			it--;
			ll na = (dp[todel.second] - dp[*it]) / ll(b[*it] - b[todel.second]);
			if (na * ll(b[*it] - b[todel.second]) < dp[todel.second] - dp[*it]) na++;
			E.insert(ii(na, todel.second));
		}
	}
	return dp[*S.begin()] + ll(b[*S.begin()]) * a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	dp[0] = 0ll; Add(0);
	for (int i = 1; i < n; i++) {
		dp[i] = Get(a[i]); Add(i);
	}
	printf("%I64d\n", dp[n - 1]);
	return 0;
}