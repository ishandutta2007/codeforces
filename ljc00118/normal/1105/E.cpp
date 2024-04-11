#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 45;

map <string, int> wxw;
int mp[N][N], tmp[N], t[N]; ll zt[N];
int n, m, cnt, ans;

int main() {
	srand(20050426);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(register int i = 1; i <= n; i++) {
		int opt; cin >> opt;
		if(opt == 1) memset(tmp, 0, sizeof(tmp));
		else {
			string t; cin >> t; int now;
			if(!wxw.count(t)) wxw[t] = now = ++cnt;
			else now = wxw[t];
			for(register int j = 1; j <= m; j++) {
				if(tmp[j]) {
					mp[j][now] = mp[now][j] = 1;
				}
			}
			tmp[now] = 1;
		}
	}
	for(register int i = 1; i <= m; i++) {
		ll now = 0;
		for(register int j = 1; j <= m; j++) {
			if(mp[i][j]) now ^= (1ll << (j - 1));
		}
		zt[i] = now;
		t[i] = i;
	}
	for(register int i = 1; i <= 300000; i++) {
		for(register int j = 1; j <= m * 2; j++) swap(t[rand() % m + 1], t[rand() % m + 1]);
		ll now = 0; int res = 0;
		for(register int j = 1; j <= m; j++) {
			if((now & (1ll << (t[j] - 1))) == 0) {
				++res;
				now |= zt[t[j]];
			}
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}