#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

ll x;
vector <llll> res;

int main()
{
	scanf("%I64d", &x); x *= 6;
	for (ll n = 1; n <= 2000000; n++) {
		ll gt = n * (n + 1);
		if (x % gt == 0) {
			ll lft = x / gt + n - 1;
			ll m;
			if (lft % 3 == 0) {
				m = lft / 3;
				if (n <= m) {
					res.push_back(llll(n, m));
					if (n != m) res.push_back(llll(m, n));
				}
			}
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%I64d %I64d\n", res[i].first, res[i].second);
	return 0;
}