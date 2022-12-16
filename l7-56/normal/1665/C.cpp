#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 2e5 + 10;
int n,fa[maxn],siz[maxn];
vector <int> a;
void work() {
	int ans = 0;
	read(n);
	for (int i = 1; i <= n; ++i) siz[i] = 0;
	for (int i = 2; i <= n; ++i) read(fa[i]), siz[fa[i]]++;
	a.clear(), a.push_back(1);
	for (int i = 1; i <= n; ++i) if (siz[i]) a.push_back(siz[i]);
	sort(a.begin(), a.end(), greater <int> ());
	ans += a.size();
	for (int i = 0; i < (int) a.size(); ++i) a[i] = max(0, a[i] - ((int) a.size() - i));
	sort(a.begin(), a.end(), greater <int> ());
	int sum = 0;
	for (int x : a) sum += x;
	for (int tim = 0, cnt = a.size(); sum > 0; ) {
		++ans, ++tim;
		while (cnt > 0 && a[cnt - 1] < tim) --cnt;
		sum -= cnt + 1;
	}
	write(ans, '\n');
}

int main() {
	int t; read(t);
	while (t--) work();
	return 0;
}