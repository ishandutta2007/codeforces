#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef pair <ld, ii> ldii;
typedef long long ll;

const int Maxn = 100005;
const ll arg1 = 1645417;

int n, m;
ii p[Maxn];
ll pw1;

ll Cross(const ii &a, const ii &b, const ii &c)
{
	int ax = b.first - a.first, ay = b.second - a.second;
	int bx = c.first - a.first, by = c.second - a.second;
	return ll(ax) * by - ll(ay) * bx;
}

ll Dot(const ii &a, const ii &b, const ii &c)
{
	int ax = b.first - a.first, ay = b.second - a.second;
	int bx = c.first - a.first, by = c.second - a.second;
	return ll(ax) * bx + ll(ay) * by;
}

bool inLine(const ii &a, const ii &b, const ii &c) { return Cross(a, b, c) == 0; }

bool Eliminate(const ii &a, const ii &b, const ii &c) { return Cross(a, c, b) >= 0; }

ll Dist(const ii &a, const ii &b) { return ll(a.first - b.first) * (a.first - b.first) +
										   ll(a.second - b.second) * (a.second - b.second); }

bool Less(const ldii &a, const ldii &b)
{
	if (inLine(p[0], a.second, b.second))
		return Dist(p[0], a.second) < Dist(p[0], b.second);
	return a.first < b.first;
}

vector <ll> getHull(int n)
{
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
		if (p[i] < p[0]) swap(p[0], p[i]);
	}
	vector <ldii> seq;
	for (int i = 1; i < n; i++)
		seq.push_back(ldii(atan2(ld(p[i].second - p[0].second), ld(p[i].first - p[0].first)), p[i]));
	sort(seq.begin(), seq.end(), Less);
	vector <ii> hull;
	hull.push_back(p[0]);
	for (int i = 0; i < seq.size(); i++) {
		ii cur = seq[i].second;
		while (hull.size() >= 2 && Eliminate(hull[int(hull.size()) - 2], hull.back(), cur))
			hull.pop_back();
		hull.push_back(cur);
	}
	while (hull.size() >= 3 && Eliminate(hull[int(hull.size()) - 2], hull.back(), p[0]))
		hull.pop_back();
	vector <ll> res;
	for (int i = 0; i < hull.size(); i++) {
		int ni = (i + 1) % int(hull.size());
		res.push_back(Dist(hull[i], hull[ni]));
		int nni = (i + 2) % int(hull.size());
		res.push_back(Cross(hull[i], hull[ni], hull[nni]));
		res.push_back(Dot(hull[i], hull[ni], hull[nni]));
	}
	return res;
}

ll Add(ll h, ll val)
{
	return h * arg1 + val;
}

ll Sub(ll h, ll val)
{
	return h - pw1 * val;
}

int main()
{
	scanf("%d %d", &n, &m);
	vector <ll> A = getHull(n);
	vector <ll> B = getHull(m);
	if (A.size() != B.size()) { printf("NO\n"); return 0; }
	pw1 = 1;
	for (int i = 0; i + 1 < A.size(); i++)
		pw1 *= arg1;
	ll targ = 0;
	for (int i = 0; i < A.size(); i++)
		targ = Add(targ, A[i]);
	ll cur = 0;
	for (int i = 0; i < B.size(); i++)
		cur = Add(cur, B[i]);
	bool ok = false;
	for (int i = 0; i < B.size() && !ok; i++) {
		cur = Sub(cur, B[i]);
		cur = Add(cur, B[i]);
		if (i % 3 == 2) ok = targ == cur;
	}
	printf("%s\n", ok? "YES": "NO");
	return 0;
}