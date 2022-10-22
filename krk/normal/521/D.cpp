#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

struct frac {
	ll a, b;
	frac(ll a = 0, ll b = 0): a(a), b(b) {}
	bool operator<(const frac &u) const {
		return a * u.b < b * u.a;
	}
};
typedef pair <frac, ii> fii;

int k, n, m;
ll a[Maxn];
int qtyp[Maxn], qind[Maxn], qb[Maxn];
ii best[Maxn];
vector <ii> cand[Maxn];
vector <ii> res;

int main()
{

	scanf("%d %d %d", &k, &n, &m);
	for (int i = 1; i <= k; i++)
		scanf("%I64d", &a[i]);
	priority_queue <fii> Q;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &qtyp[i], &qind[i], &qb[i]);
		if (qtyp[i] == 1) {
			if (qb[i] > best[qind[i]].first)
				best[qind[i]] = ii(qb[i], i);
		} else if (qtyp[i] == 2)
			cand[qind[i]].push_back(ii(qb[i], i));
		else Q.push(fii(frac(qb[i] - 1, 1), ii(i, qind[i])));
	}
	for (int i = 1; i <= k; i++) {
		if (best[i].first > a[i])
			cand[i].push_back(ii(best[i].first - a[i], best[i].second));
		sort(cand[i].begin(), cand[i].end());
		if (cand[i].size() > 0)
			Q.push(fii(frac(cand[i].back().first, a[i]), ii(cand[i].back().second, i)));
	}
	while (!Q.empty() && m > 0) {
		fii v = Q.top(); Q.pop();
		res.push_back(ii(qtyp[v.second.first], v.second.first));
		m--;
		if (qtyp[v.second.first] <= 2) {
			int ind = v.second.second;
			a[ind] += v.first.a;
			cand[ind].pop_back();
			if (cand[ind].size() > 0)
				Q.push(fii(frac(cand[ind].back().first, a[ind]), ii(cand[ind].back().second, ind)));
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i].second, i + 1 < res.size()? ' ': '\n');
    return 0;
}