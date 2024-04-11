#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
vector <ll> divs;
ll res;

int main()
{
	scanf("%I64d", &n);
	if (n % 3ll) { printf("0\n"); return 0; }
	n /= 3ll;
	for (ll x = 1; x * x <= n; x++)
		if (n % x == 0ll) {
			divs.push_back(x);
			if (n / x != x) divs.push_back(n / x);
		}
	sort(divs.begin(), divs.end());
	for (int i = 0; i < divs.size() && divs[i] * divs[i] * divs[i] <= n; i++)
		for (int j = i; j < divs.size() && divs[i] * divs[j] * divs[j] <= n; j++) if (n % (divs[i] * divs[j]) == 0ll) {
			int l = lower_bound(divs.begin() + j, divs.end(), n / (divs[i] * divs[j])) - divs.begin();
			if (divs[i] * divs[j] * divs[l] == n) {
				ll a = divs[i] + divs[j] - divs[l], b = divs[i] + divs[l] - divs[j], c = divs[j] + divs[l] - divs[i];
				if (a <= 0 || b <= 0 || c <= 0 || a % 2ll || b % 2ll || c % 2ll) continue;
				if (a == b && b == c) res++;
				else if (a == b || a == c || b == c) res += 3;
				else res += 6;
			}
		}
	printf("%I64d\n", res);
	return 0;
}