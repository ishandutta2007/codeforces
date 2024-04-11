#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 2e5 + 5;

vector <pii> tmp;
vector <int> pos[N], posx[N], posy[N];
int x[N], y[N];
int X, Y, n, m; ll ans;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void exgcd(int a, int b, int &x, int &y) {
	if (b == 0) { x = 1; y = 0; return; }
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
}

int inv(int a, int md) {
	int x, y;
	exgcd(a, md, x, y);
	return (x % md + md) % md;
}

ll solve(vector <int> pos, vector <int> have, int n, int go, int cost) {
	tmp.clear();
	int inv_go = inv(go, n);
	for (int i = 0; i < (int)pos.size(); i++) tmp.emplace_back((int)(1ll * pos[i] * inv_go % n), pos[i]);
	for (int i = 0; i < (int)have.size(); i++) have[i] = 1ll * have[i] * inv_go % n;
	sort(tmp.begin(), tmp.end()); sort(have.begin(), have.end());
	ll minn = tmp[0].second, maxn = 0;
	for (int i = 1; i < (int)tmp.size(); i++) {
		minn += 1ll * (tmp[i].first - tmp[i - 1].first) * cost;
		minn = min(minn, (ll)tmp[i].second);
	}
	for (int i = 0; i < (int)tmp.size(); i++) {
		if (i == 0) minn += 1ll * (tmp[0].first + n - tmp[tmp.size() - 1].first) * cost;
		else minn += 1ll * (tmp[i].first - tmp[i - 1].first) * cost;
		int _pos = lower_bound(have.begin(), have.end(), (tmp[i].first + n - 1) % n) - have.begin();
		// cout << minn << " " << n << " " << go << " " << cost << endl;
		if (_pos == have.size() || have[_pos] != (tmp[i].first + n - 1) % n) maxn = max(maxn, minn - cost);
		minn = min(minn, (ll)tmp[i].second);
	}
	return maxn;
}

int main() {
	read(X); read(Y);
	int d = gcd(X, Y);
	X /= d; Y /= d;
	if (d > 200000) {
		print(-1, '\n');
		return 0;
	}
	read(n);
	for (int i = 1; i <= n; i++) read(x[i]), pos[x[i] % d].push_back(x[i] / d), posx[x[i] % d].push_back(x[i] / d);
	read(m);
	for (int i = 1; i <= m; i++) read(y[i]), pos[y[i] % d].push_back(y[i] / d), posy[y[i] % d].push_back(y[i] / d);
	for (int i = 0; i < d; i++) {
		if (pos[i].size() == 0) {
			print(-1, '\n');
			return 0;
		}
		ll res = max(solve(pos[i], posx[i], X, Y % X, Y), solve(pos[i], posy[i], Y, X % Y, X));
		if (posx[i].size() != X || posy[i].size() != Y) ans = max(ans, res * d + i);
	}
	print(ans, '\n');
	return 0;
}