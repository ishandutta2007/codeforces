#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 2e5 + 10;
int n,m;
ll L,R;
vector <int> v[maxn];
set <pii> s;

int main() {
	read(n, m, L, R);
	for (int i = 1; i <= max(n, m); ++i)
		for (int j = i; j <= max(n, m); j += i)
			v[j].push_back(i);
	int l = m, r = m;
	for (int x = 1; x <= n; ++x) {
		for (; 1ll * x * l >= L; --l)
			if (l <= r)
				for (int b : v[l]) s.insert({b, l});
		for (; 1ll * x * r > R; --r)
			if (l < r)
				for (int b : v[r]) s.erase({b, r});
		for (int a : v[x]) {
			auto it = s.upper_bound(make_pair(a, INT_MAX));
			if (it == s.end()) continue;
			int b = it -> first, y = it -> second;
			if (1ll * x * b / a <= n) {
				write(x, ' ', y, ' ', x / a * b, ' ', y / b * a, '\n');
				goto done;
			}
		}
		write(-1, '\n');
		done: ;
	}
	return 0;
}