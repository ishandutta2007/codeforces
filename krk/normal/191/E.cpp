#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll lim = 100000000000000ll;
const int Maxn = 100005;

int n;
ll k;
ll a[Maxn];
ll sum[Maxn];
vector <ll> un;
int BIT[Maxn];
ll res;

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

void Insert(int x)
{
	for (int i = x; i <= un.size(); i += i & -i)
		BIT[i]++;
}

bool Enough(ll x)
{
	fill(BIT, BIT + un.size() + 1, 0);
	ll res = 0ll;
	Insert(lower_bound(un.begin(), un.end(), 0ll) - un.begin() + 1);
	for (int i = 0; i < n; i++) {
		int ind = upper_bound(un.begin(), un.end(), sum[i] - x) - un.begin();
		res += Get(ind);
		ind = lower_bound(un.begin(), un.end(), sum[i]) - un.begin() + 1;
		Insert(ind);
	}
	return res >= k;
}

int main()
{
	scanf("%d %I64d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		sum[i] = (i? sum[i - 1]: 0ll) + a[i];
		un.push_back(sum[i]);
	}
	un.push_back(0);
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	ll lef = -lim, rig = lim;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Enough(mid)) { res = mid; lef = mid + 1ll; }
		else rig = mid - 1ll;
	}
	printf("%I64d\n", res);
	return 0;
}