#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const ll P = 998244353;

inline int lowbit(int x) { return x & -x; }

pair <ll, ll> f[20][1 << 11][2][2];
ll num[20], bit[1 << 11], bin[20];
ll l, r, k, len;

pair <ll, ll> dfs(int u, int zt, int ismaxn, int iszero) {
//	fprintf(stderr, "< %d %d %d %d >\n", u, zt, ismaxn, iszero);
	if(u == 0) return make_pair(0ll, bit[zt] <= k && !iszero);
	if(~f[u][zt][ismaxn][iszero].first) return f[u][zt][ismaxn][iszero];
	pair <ll, ll> &ans = f[u][zt][ismaxn][iszero]; ans.first = ans.second = 0;
	int Max = 9; if(ismaxn) Max = num[u];
	for(register int i = 0; i <= Max; i++) {	
		pair <ll, ll> t = dfs(u - 1, (iszero && !i) ? zt : (zt | (1 << i)), ismaxn && (i == num[u]), iszero && (i == 0));
		ans.first += t.first + t.second * i % P * bin[u - 1] % P; ans.second += t.second;
		ans.first %= P; ans.second %= P;
	}
	return ans;
}

ll solve(ll x) {
	if(x == 0) return 0;
	memset(f, -1, sizeof(f)); ll ans = 0;
	len = 0; while(x) num[++len] = x % 10, x /= 10;
	for(register int i = 0; i <= num[len]; i++) {
		ans += dfs(len - 1, i == 0 ? 0 : (1 << i), i == num[len], i == 0).first; ans %= P;
		ans += dfs(len - 1, i == 0 ? 0 : (1 << i), i == num[len], i == 0).second * i % P * bin[len - 1] % P; ans %= P;
	}
	return ans;
}

int main() {
	read(l); read(r); read(k);
	bit[0] = 0; for(register int i = 1; i < (1 << 10); i++) bit[i] = bit[i ^ lowbit(i)] + 1;
	bin[0] = 1; for(register int i = 1; i <= 18; i++) bin[i] = bin[i - 1] * 10 % P;
	cout << (solve(r) - solve(l - 1) + P) % P << endl;
	return 0;
}