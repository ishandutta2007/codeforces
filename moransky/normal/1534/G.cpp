// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 8e5 + 5;

int n;

PII e[N];

LL k, b;

priority_queue<LL> L;
priority_queue<LL, vector<LL>, greater<LL> > R;

LL dl, dr;

int main() {
	read(n);
	for (int i = 1, x, y; i <= n; i++) {
		read(x), read(y);
		e[i] = mp(x + y, x);
	}
	sort(e + 1, e + 1 + n);
	for (int i = 1; i <= n; i++) k += -1, b += e[i].se;
	L.push(e[1].se), R.push(e[1].se);
	for (int i = 2; i <= n; i++) {
		LL o = e[i].fi - e[i - 1].fi;
		dr += o;
		LL x = e[i].se;
		if (x <= R.top() + dr) {
			L.push(x - dl);
			L.push(x - dl);
			LL nx = L.top() + dl;
			L.pop();
			R.push(nx - dr);
		} else {
			R.push(x - dr);
			R.push(x - dr);
			LL nx = R.top() + dr;
			R.pop();
			L.push(nx - dl);
		}
	}
	LL x = R.top() + dr;
	LL ans = k * x + b;
	while (!L.empty()) {
		LL u = L.top() + dl; L.pop();
		ans += (x - u);
	}
	printf("%lld\n", ans);
    return 0;
}