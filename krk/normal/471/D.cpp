#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 200005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

ll a1[Maxn], a2[Maxn];
int n, w;
int a[Maxn], b[Maxn];
vector <int> un;
ii H[Maxn];
int res;

ii getHash(int l, int r)
{
	l--;
	ii res = ii(H[r].first - H[l].first * a1[r - l] % mod1, H[r].second - H[l].second * a2[r - l] % mod2);
	if (res.first < 0) res.first += mod1; res.first %= mod1;
	if (res.second < 0) res.second += mod2; res.second %= mod2;
	return res;
}

int main()
{
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i > 1) {
			a[i - 1] = a[i] - a[i - 1];
			un.push_back(a[i - 1]);
		}
	}
	n--;
	for (int i = 1; i <= w; i++) {
		scanf("%d", &b[i]);
		if (i > 1) {
			b[i - 1] = b[i] - b[i - 1];
			un.push_back(b[i - 1]);
		}
	}
	w--;
	if (w == 0) { printf("%d\n", n + 1); return 0; }
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	a1[0] = a2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		a1[i] = a1[i - 1] * 146442479 % mod1;
		a2[i] = a2[i - 1] * 37 % mod2;
	}
	H[0] = ii(0, 0);
	for (int i = 1; i <= n; i++) {
		int val = lower_bound(un.begin(), un.end(), a[i]) - un.begin() + 1;
		H[i] = ii((H[i - 1].first * a1[1] + val) % mod1, (H[i - 1].second * a2[1] + val) % mod2);
	}
	ii myhash = ii(0, 0);
	for (int i = 1; i <= w; i++) {
		int val = lower_bound(un.begin(), un.end(), b[i]) - un.begin() + 1;
		myhash = ii((myhash.first * a1[1] + val) % mod1, (myhash.second * a2[1] + val) % mod2); 
	}
	for (int i = 1; i + w <= n + 1; i++)
		res += getHash(i, i + w - 1) == myhash;
	printf("%d\n", res);
	return 0;
}