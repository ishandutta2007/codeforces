#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int t;
ll n, k, d1, d2;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
		bool was = false;
		for (ll i = -1; i <= 1 && !was; i += 2)
			for (ll j = -1; j <= 1 && !was; j += 2) {
				ll nd1 = i * d1, nd2 = j * d2;
				ll lft = k - nd1 - nd2;
				if (lft < 0 || lft % 3ll) continue;
				ll w2 = lft / 3ll;
				ll w1 = w2 + nd1, w3 = w2 + nd2;
				if (w1 < 0 || w2 < 0 || w3 < 0) continue;
				if (w1 > w2) swap(w1, w2);
				if (w2 > w3) swap(w2, w3);
				if (w1 > w2) swap(w1, w2);
				lft = n - k - (w3 - w1) - (w3 - w2);
				if (lft < 0 || lft % 3ll) continue;
				was = true;
			}
		printf("%s\n", was? "yes": "no");
	}
	return 0;
}