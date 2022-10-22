//test 
#include <bits/stdc++.h>
#define par pair<int, int>
#define mp make_pair
#define x first
#define y second
#define sz(a) int((a).size())
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int n, m, b, g, x[N], y[N];
vector<int> le[N], ri[N];
map<int, int> el, er;

void exgcd(i64 a, i64 b, i64 &d, i64 &x, i64 &y) {
	if(!b) {
		d = a, x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, d, y, x);
	y -= a / b * x;
	return;
}

i64 dist(int a, int b, int delta) {
	delta = (delta % a + a) % a;
	i64 d, x, y;
	exgcd(a, b, d, x, y);
	y = (y % a + a) % a;
	return y * delta % a;
}


i64 solve(vector<int> l, vector<int> r) {
	sort(l.begin(), l.end()), sort(r.begin(), r.end());
	el.clear(), er.clear();
	for(int i = 0; i < sz(l); i++) el[l[i]] = 1;
	for(int i = 0; i < sz(r); i++) er[r[i]] = 1;
	vector<int> nl = l, nr = r;
	i64 tim = -1;
	for(int i = 0; i < sz(l); i++) {
		int cur = l[i] % m;
		if(!er.count(cur)) nr.push_back(cur), er[cur] = 1, tim = max(tim, (i64)l[i]);
	}
	for(int i = 0; i < sz(r); i++) {
		int cur = r[i] % n;
		if(!el.count(cur)) nl.push_back(cur), el[cur] = 1, tim = max(tim, (i64)r[i]);
	}
	vector<i64> L, R;
	for(int i = 0; i < sz(nl); i++) {
		L.push_back(dist(n, m, nl[i] - nl[0]));
	}
	for(int i = 0; i < sz(nr); i++) {
		R.push_back(dist(m, n, nr[i] - nr[0]));
	}
	L.push_back(n), R.push_back(m);
	sort(L.begin(), L.end()), sort(R.begin(), R.end());
	for(int i = 1; i < sz(L); i++) {
		if(L[i] == L[i - 1] + 1) continue;
		tim = max(tim, (L[i] - L[i - 1] - 1) * m + (L[i - 1] * m + nl[0]) % n);
	}
	for(int i = 1; i < sz(R); i++) {
		if(R[i] == R[i - 1] + 1) continue;
		tim = max(tim, (R[i] - R[i - 1] - 1) * n + (R[i - 1] * n + nr[0]) % m);
	}
	return tim;
}

int main() {
	cin >> n >> m;
	int G = __gcd(n, m);
	cin >> b;
	for(int i = 0; i < b; i++) {
		cin >> x[i];
	}
	cin >> g;
	for(int i = 0; i < g; i++) {
		cin >> y[i];
	}
	if(b + g < G) return cout << "-1" << endl, 0;
	for(int i = 0; i < b; i++) {
		le[x[i] % G].push_back((x[i] - x[i] % G) / G);
	}
	for(int i = 0; i < g; i++) {
		ri[y[i] % G].push_back((y[i] - y[i] % G) / G);
	}
	n /= G, m /= G;
	i64 ans = 0;
	for(int i = 0; i < G; i++) {
		if(le[i].empty() && ri[i].empty()) return cout << "-1" << endl, 0;
		ans = max(ans, solve(le[i], ri[i]) * G + i);
	}
	cout << ans << endl;
    return 0;
}