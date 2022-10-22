#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;

ll n, t;
map <ii, ll> mem;
ll res;

ll f(int id, ll t)
{
	if (id == 1) return t == 1ll || t == 2ll;
	ii p = make_pair(id, t);
	if (mem.find(p) == mem.end()) {
		ll res = f(id - 1, t);
		if (t % 2ll == 0ll) res += f(id - 1, t / 2ll);
		mem[p] = res;
	}
	return mem[p];
}

ll g(int id, ll lin, ll t)
{
	if (id == 1) return lin == 0 && t == 1ll || lin == 1 && (t == 1ll || t == 2ll);
	if (lin < 1ll << id - 1) return g(id - 1, lin, t);
	else {
		ll res = f(id - 1, t);
		if (t % 2ll == 0ll) res += g(id - 1, lin - (1ll << id - 1), t / 2ll);
		return res;
	}
}

int main()
{
	scanf("%I64d %I64d", &n, &t);
	int id = 1;
	while (1ll << id + 1 <= n + 1ll) { res += f(id, t); id++; }
	res += g(id, n + 1ll - (1ll << id), t);
	printf("%I64d\n", res);
	return 0;
}