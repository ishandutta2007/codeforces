#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 100005;

int n, p, q;
ii ab[Maxn];
ld res = 1e30;
vector <ii> V;

bool Less(const ii &a, const ii &b)
{
	ll fir = ll(a.second) * b.first;
	ll sec = ll(a.first) * b.second;
	if (fir != sec) return fir < sec;
	return ll(a.first) * a.first + ll(a.second) * a.second < ll(b.first) * b.first + ll(b.second) * b.second;
}

int main()
{
	scanf("%d %d %d", &n, &p, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ab[i].first, &ab[i].second);
		res = min(res, max(ld(p) / ab[i].first, ld(q) / ab[i].second));
	}
	sort(ab, ab + n, Less);
	V.push_back(ii(0, 0));
	for (int i = 0; i < n; i++) {
		while (V.size() >= 2) {
			int ax = V.back().first - V[V.size() - 2].first, ay = V.back().second - V[V.size() - 2].second;
			int bx = ab[i].first - V.back().first, by = ab[i].second - V.back().second;
			if (ll(bx) * ay - ll(by) * ax >= 0) V.pop_back(); 
			else break;
		}
		V.push_back(ab[i]);
	}
	for (int i = 1; i + 1 < V.size(); i++)
		if (ll(V[i].first) * q - ll(V[i].second) * p >= 0 && ll(p) * V[i + 1].second - ll(q) * V[i + 1].first >= 0) {
			int cnt = 500;
			ld lft = 0, rgt = 10000000;
			ld r;
			while (cnt--) {
				ld mid = (lft + rgt) / 2.0l;
				ld curx = p * mid, cury = q * mid;
				ld ax = curx - V[i].first, ay = cury - V[i].second;
				ld bx = V[i + 1].first - V[i].first, by = V[i + 1].second - V[i].second;
				if (ax * by - ay * bx >= 0) { r = mid; rgt = mid; }
				else lft = mid;
			}
			res = min(res, 1.0l / r);
		}
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}