#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxb = 62;

int n;
ll a[Maxn];
ll bas[Maxb];
int ind[Maxb];
ll wth[Maxb];
ll all;
int res[Maxn];

void Update(set <int> &S, int x)
{
	auto it = S.find(x);
	if (it == S.end())
		S.insert(x);
	else S.erase(it);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		all ^= a[i];
	}
	int basic = 0;
	for (int i = 0; i < Maxb; i++)
		if (all & 1ll << ll(i)) basic++;
	for (int i = 0; i < n; i++) {
		ll mask = 0;
		for (int b = Maxb - 1; b >= 0; b--)
			if (!(all & 1ll << ll(b)))
				mask = (mask << 1ll) | bool(a[i] & 1ll << ll(b));
		for (int b = Maxb - 1; b >= 0; b--)
			if (all & 1ll << ll(b))
				mask = (mask << 1ll) | bool(a[i] & 1ll << ll(b));
		ll usd = 0;
		for (int b = Maxb - 1; b >= 0; b--)
			if (mask & 1ll << ll(b)) {
				if (bas[b]) {
					mask ^= bas[b];
					usd ^= wth[b];
				} else {
					usd |= 1ll << ll(b);
					bas[b] = mask;
					ind[b] = i;
					wth[b] = usd;
					break;
				}
			}
	}
	ll cur = 0;
	ll mask = 0;
	for (int i = Maxb - 1; i >= 0; i--)
		if (i >= basic && !(cur & 1ll << ll(i)) ||
			i < basic && bool(cur & 1ll << ll(i))) {
			cur ^= bas[i];
			mask ^= wth[i];
		}
	for (int i = 0; i < Maxb; i++)
		if (mask & 1ll << ll(i))
			res[ind[i]]--;
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i] + 2, i + 1 < n? ' ': '\n');
    return 0;
}