#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;

int n;
ll s;
pair <int, int> cv[Maxn];
deque <llll> L;
deque <ll> X;
ll res = 1000000000000000000ll;

ll getX(const llll &fir, const llll &sec)
{
	return (fir.first - sec.first - 1) / (sec.second - fir.second) + 1;
}

void Add(const llll &lin)
{
	while (!L.empty() && lin.first >= L.back().first) { L.pop_back(); X.pop_back(); }
	while (L.size() >= 2) {
		ll x = getX(L.back(), lin);
		if (x <= X.back()) { L.pop_back(); X.pop_back(); }
		else break;
	}
	if (L.empty()) X.push_back(0);
	else X.push_back(getX(L.back(), lin));
	L.push_back(lin);
}

llll getTim(ll cookies)
{
	if (X.empty()) return llll(0ll, 0ll);
	ll tim;
	while (true) {
		tim = (cookies - L[0].first) / L[0].second;
		if (L[0].first + L[0].second * tim < cookies) tim++;
		if (X.size() >= 2 && X[1] <= tim) {
			X.pop_front();
			L.pop_front();
		} else break;
	}
	return llll(tim, L[0].first + L[0].second * tim);
}

int main()
{
	scanf("%d %I64d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &cv[i].second, &cv[i].first);
	sort(cv, cv + n);
	int mxv = 0;
	for (int i = 0; i < n; i++) if (mxv < cv[i].second) {
		mxv = cv[i].second;
		auto tim_val = getTim(cv[i].first);
		tim_val.second -= cv[i].first;
		if (tim_val.second >= s) res = min(res, tim_val.first);
		else res = min(res, tim_val.first + (s - tim_val.second - 1) / cv[i].second + 1);
		Add(llll(tim_val.second - tim_val.first * cv[i].second, cv[i].second));
	}
	cout << res << endl;
    return 0;
}