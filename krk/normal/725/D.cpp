#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 300005;
const int Maxm = 2097152;
const ll Inf = 2000000000000000000ll;

int n;
ll myt, myw;
vector <llll> p;
ll need[Maxm];
int cnt[Maxm];
vector <ll> un;
int best = Maxn;

void Update(int v, int l, int r, int x)
{
	cnt[v]++; need[v] = min(Inf, need[v] + un[x]);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x);
		else Update(2 * v + 1, m + 1, r, x);
	}
}

int Get(int v, int l, int r, ll &x)
{
	if (need[v] <= x) { x -= need[v]; return cnt[v]; }
	if (l == r) {
		int tk = x / un[l];
		x -= un[l] * tk; return tk;
	} else {
		int res = 0;
		int m = l + r >> 1;
		if (need[2 * v] <= x) {
			x -= need[2 * v]; res += cnt[2 * v];
			res += Get(2 * v + 1, m + 1, r, x);
		} else res += Get(2 * v, l, m, x);
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%I64d %I64d", &myt, &myw);
	p.resize(n - 1);
	for (int i = 0; i < n - 1; i++) {
		scanf("%I64d %I64d", &p[i].first, &p[i].second);
		un.push_back(p[i].second - p[i].first + 1ll);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	sort(p.rbegin(), p.rend());
	for (int i = 0; i < p.size(); i++) {
		if (myt >= p[i].first && (i == 0 || p[i].first != p[i - 1].first)) { 
			ll has = myt - p[i].first; 
			best = min(best, i - Get(1, 0, un.size() - 1, has)); 
		}
		int ind = lower_bound(un.begin(), un.end(), p[i].second - p[i].first + 1ll) - un.begin();
		Update(1, 0, un.size() - 1, ind);
	}
	if (p.back().first > 0) {
		ll has = myt; best = min(best, int(p.size()) - Get(1, 0, un.size() - 1, has));
	}
	printf("%d\n", best + 1);
	return 0;
}