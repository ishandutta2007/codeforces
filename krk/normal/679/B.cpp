#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const ll Inf = 1000000000000000ll;
const int Maxn = 100000;

map <ll, llll> M;
ll m;

llll Get(ll m)
{
	if (m == 0) return llll(0, 0);
	if (M.find(m) == M.end()) {
		ll lef = 1, rig = Maxn;
		ll res;
		while (lef <= rig) {
			ll mid = lef + rig >> 1ll;
			if (mid * mid * mid <= m) { res = mid; lef = mid + 1ll; }
			else rig = mid - 1ll;
		}
		ll tk = res * res * res;
		llll a = Get(tk - 1), b = Get(m - tk);
		b.first++; b.second += tk;
		if (a.first <= b.first)
			M[m] = b;
		else M[m] = a;
	}
	return M[m];
}

int main()
{
	scanf("%I64d", &m);
	llll res = Get(m);
	printf("%I64d %I64d\n", res.first, res.second);
	return 0;
}