#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10;
ll n,q,sum[maxn];
struct BIT {
	ll c[maxn];
	void add(ll pos, ll val) { for (; pos <= n; pos += pos & (-pos)) c[pos] += val; }
	void add(ll l, ll r, ll val) { add(l, val), add(r + 1, -val); }
	ll ask(ll pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
}T;
set <ll> pos;
ll col[maxn];

typedef set <ll> :: iterator It;

void update(ll l, ll r, ll c) {
	It it = pos.upper_bound(l), nx = it; --it;
	ll c0 = col[*it];
	if ((*nx) - 1 > r) {
		T.add(l, r, sum[c0] - sum[c]);
		pos.insert(l), pos.insert(r + 1);
		col[l] = c, col[r + 1] = c0;
		return;
	}
	T.add(l, (*nx) - 1, sum[c0]);
	for (it = nx, ++nx; (*nx) - 1 <= r; pos.erase(it), it = nx, ++nx)
		c0 = col[*it], T.add(*it, (*nx) - 1, sum[c0]);
	if ((*it) <= r) {
		c0 = col[*it], T.add(max(*it, l), r, sum[c0]);
		pos.erase(it), pos.insert(r + 1), col[r + 1] = c0;
	}
	pos.insert(l), col[l] = c, T.add(l, r, -sum[c]);
}

ll query(ll x) {
	It it = --pos.upper_bound(x); ll c = col[*it];
	return T.ask(x) + sum[c];
}

void print() {
	for (ll x : pos) printf("|%lld", x);
	printf("|\n");
	for (ll x : pos) printf("|%lld", col[x]);
	printf("|\n");
}

int main() {
    scanf("%lld%lld", &n, &q);
	pos.insert(1), pos.insert(n + 1), pos.insert(n + 2), col[1] = 1;
    for (ll t = 1; t <= q; ++t) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'C') {
            ll l, r, c;
            scanf("%lld%lld%lld", &l, &r, &c);
	        update(l, r, c);
        }
        else if (op[0] == 'A') {
            ll c, x;
            scanf("%lld%lld", &c, &x);
            sum[c] += x;
        }
        else {
            ll i;
            scanf("%lld", &i);
            printf("%lld\n", query(i));
        }
    }
	return 0;
}