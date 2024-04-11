#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;

int n;
int k[Maxn], b[Maxn];
vector <ld> pnts;
ll delta[Maxn], a[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &k[i], &b[i]);
		if (k[i]) pnts.push_back(-ld(b[i]) / ld(k[i]));
	}
	sort(pnts.begin(), pnts.end()); pnts.erase(unique(pnts.begin(), pnts.end()), pnts.end());
	for (int i = 0; i < n; i++)
		if (k[i] > 0) {
			int ind = lower_bound(pnts.begin(), pnts.end(), -ld(b[i]) / ld(k[i])) - pnts.begin();
			delta[ind + 1] += k[i]; delta[pnts.size() + 1] -= k[i];
		} else {
			int ind = upper_bound(pnts.begin(), pnts.end(), -ld(b[i]) / ld(k[i])) - pnts.begin() - 1;
			delta[0] += k[i]; delta[ind + 1] -= k[i];
		}
	ll cur = 0ll;
	for (int i = 0; i <= pnts.size(); i++) {
		cur += delta[i];
		a[i] = cur;
	}
	for (int i = 0; i < pnts.size(); i++)
		res += a[i] != a[i + 1];
	printf("%d\n", res);
	return 0;
}