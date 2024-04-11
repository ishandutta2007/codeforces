#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

ll n;
map <ii, ii> M;

ii Get(ll n, int mx)
{
	if (n <= 0ll) return ii(0ll, n);
	ii p = ii(n, mx);
	if (!M.count(p)) {
		ll a = 1;
		while (a <= n / 10ll) a *= 10ll;
		int dig = n / a;
		ii res = ii(0ll, n % a);
		while (dig > 0 || res.second > 0) {
			ii tmp = Get(res.second, max(mx, dig));
			res.first += tmp.first; res.second = tmp.second;
			if (dig > 0 && res.second == 0) { res.first++; res.second -= max(mx, dig); }
			if (dig > 0 && res.second != 0) { dig--; res.second += a; }
		}
		M[p] = res;
	}
	return M[p];
}

int main()
{
	scanf("%I64d", &n);
	printf("%I64d\n", Get(n, 0).first);
	return 0;
}