#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

ll k, l, r, t;
int x;
ll y;
bool tk[Maxn];

int main()
{
	cin >> k >> l >> r >> t >> x >> y;
	k -= l; r -= l;
	if (y >= x) {
		ll res = k / x;
		k %= x;
		while (!tk[k]) {
			if (k + y > r) break;
			tk[k] = true;
			k += y;
			res += k / x;
			k %= x;
		}
		if (tk[k] || res >= t)
			printf("Yes\n");
		else printf("No\n");
	} else {
		ll res = 0;
		if (k + y > r)
			if (k < x) { printf("No\n"); return 0; }
			else { res++; k -= x; }
		res += k / (x - y);
		if (res >= t)
			printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}