#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;
const ll Inf = 1000000000000000000ll;

int n;
ii ac[Maxn];
vector <int> un;
ll st[2][Maxm];
ll res;

void Create(int t, int v, int l, int r)
{
	st[t][v] = Inf;
	if (l < r) {
		int m = l + r >> 1;
		Create(t, 2 * v, l, m);
		Create(t, 2 * v + 1, m + 1, r);
	}
}

void Update(int t, int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) st[t][v] = min(st[t][v], val);
	else {
		int m = l + r >> 1;
		if (a <= m) Update(t, 2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

ll Get(int t, int v, int l, int r, int x)
{
	ll res = st[t][v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res = min(res, Get(t, 2 * v, l, m, x));
		else res = min(res, Get(t, 2 * v + 1, m + 1, r, x));
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ac[i].first, &ac[i].second);
		un.push_back(ac[i].first);
		res += ac[i].second;
	}
	sort(ac, ac + n);
	sort(un.begin(), un.end());
	un.erase(unique(un.begin(), un.end()), un.end());
	Create(0, 1, 0, int(un.size()) - 1);
	Create(1, 1, 0, int(un.size()) - 1);
	Update(0, 1, 0, int(un.size()) - 1, 0, 0, 0);
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(un.begin(), un.end(), ac[i].first) - un.begin();
		ll my = min(Get(0, 1, 0, int(un.size()) - 1, ind), ac[i].first + Get(1, 1, 0, int(un.size()) - 1, ind));
		if (i + 1 == n) { res += my; break; }
		int rig = upper_bound(un.begin(), un.end(), ac[i].first + ac[i].second) - un.begin() - 1;
		if (ind <= rig) Update(0, 1, 0, int(un.size()) - 1, ind, rig, my);
		if (rig + 1 < un.size()) Update(1, 1, 0, int(un.size()) - 1, rig + 1, int(un.size()) - 1, my - (ac[i].first + ac[i].second));
	}
	cout << res << endl;
    return 0;
}