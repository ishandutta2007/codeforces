#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;
const int lim = 1000000;

int n;
ll a[Maxn];
ll got;
ll res;
ll cur;
vector <llll> ab;
vector <ll> from;

ll getPoint(const llll &big, const llll &small)
{
	ll x = (small.first - big.first) / (big.second - small.second);
	if (x * (big.second - small.second) < (small.first - big.first)) x++;
	return x;
}

void Add(llll lin)
{
	lin.first -= cur;
	while (!ab.empty()) {
		ll x = getPoint(ab.back(), lin);
		if (x >= from.back()) {
			ab.pop_back(); from.pop_back();
		} else break;
	}
	if (ab.empty()) { ab.push_back(lin); from.push_back(lim + 1); }
	else { from.push_back(getPoint(ab.back(), lin)); ab.push_back(lin); }
}

ll Get(int x)
{
	int lef = 0, rig = int(ab.size()) - 1;
	int res = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (x < from[mid]) { res = mid; lef = mid + 1; }
		else rig = mid - 1;
	}
	return ab[res].first + cur + ab[res].second * ll(x);
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
		got += a[i] * ll(i);
	}
	res = got;
	for (int i = n; i >= 1; i--) {
		Add(llll(0, i));
		res = max(res, got + Get(a[i]) - ll(i) * a[i]);
		cur -= a[i];
	}
	cur = 0; ab.clear(); from.clear();
	for (int i = 1; i <= n; i++) {
		Add(llll(0, -i));
		res = max(res, got + Get(-a[i]) - ll(i) * a[i]);
		cur += a[i];
	}
	printf("%I64d\n", res);
    return 0;
}