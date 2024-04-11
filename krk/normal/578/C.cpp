#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;
typedef long double ld;

const int Maxn = 200005;
const ld Inf = 20000.0l;

int n;
int a[Maxn];
vector <llll> mnl, mxl;
vector <ld> mnp, mxp;
ld res = 1e60;

ld Get(const llll &a, const llll &b)
{
	return ld(b.first - a.first) / (a.second - b.second);
}

void Add(const llll &lin, vector <llll> &l, vector <ld> &p, bool flagmn)
{
	while (l.size() > 0 && (flagmn && l.back().first - Inf * l.back().second >= lin.first - Inf * lin.second ||
							!flagmn && l.back().first - Inf * l.back().second <= lin.first - Inf * lin.second)) { l.pop_back(); p.pop_back(); }
	while (l.size() > 1) {
		ld x = Get(lin, l[l.size() - 2]);
		if (x <= p.back()) { l.pop_back(); p.pop_back(); }
		else break;
	}
	if (l.empty()) p.push_back(-Inf);
	else p.push_back(Get(lin, l.back()));
	l.push_back(lin);
}

ld Get(const vector <llll> &l, const vector <ld> &p, ld x)
{
	int ind = upper_bound(p.begin(), p.end(), x) - p.begin() - 1;
	return l[ind].first + l[ind].second * x;
}

int main()
{
	scanf("%d", &n);
	Add(llll(0, 0), mnl, mnp, true);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
		Add(llll(a[i], -i), mnl, mnp, true);
	}
	for (int i = n; i >= 1; i--)
		Add(llll(a[i], -i), mxl, mxp, false);
	Add(llll(0, 0), mxl, mxp, false);
	for (int i = 0; i < mnp.size(); i++) 
		res = min(res, fabs(mnl[i].first + mnl[i].second * mnp[i] - Get(mxl, mxp, mnp[i])));
	for (int i = 0; i < mxp.size(); i++)
		res = min(res, fabs(mxl[i].first + mxl[i].second * mxp[i] - Get(mnl, mnp, mxp[i])));
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}