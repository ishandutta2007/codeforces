#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 10000005;
const ll Inf = 9000000000000000000ll;

bool prime[Maxm];
int pr[Maxm], plen;
int n;
int freq[Maxm];
ll has[Maxm];
ll res = Inf;

bool Enough(ll lim)
{
	for (int i = 0; i < plen; i++) {
		ll cur = 0ll;
		for (ll j = 1; j <= lim / ll(pr[i]) && cur < has[i]; ) {
			j *= pr[i];
			cur += lim / j;
		}
		if (cur < has[i]) return false;
	}
	return true;
}

int main()
{
	fill(prime + 2, prime + Maxm, true);
	for (int i = 2; i < Maxm; i++) if (prime[i]) {
		pr[plen++] = i;
		for (int j = i + i; j < Maxm; j += i) prime[j] = false;
	}
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		freq[a]++;
	}
	for (int i = Maxm - 2; i >= 0; i--) freq[i] += freq[i + 1];
	for (int i = 0; i < plen; i++)
		for (int j = 1; j <= (Maxm - 1) / pr[i]; ) {
			j *= pr[i];
			for (int k = j; k < Maxm; k += j) has[i] += freq[k];
		}
	ll lef = 1ll, rig = Inf;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Enough(mid)) { res = mid; rig = mid - 1ll; }
		else lef = mid + 1ll;
	}
	printf("%I64d\n", res);
	return 0;
}