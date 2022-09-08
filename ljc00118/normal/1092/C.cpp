#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
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

const int N = 205;

map <string, int> ans;
string a[N], b[N];
char c[N];
int n;

bool cmp(string a, string b) { return a.size() > b.size(); }

void solve() {
	for(register int i = 1; i <= n - 1; i++) c[i] = b[1][i - 1]; c[n] = b[2][n - 2];
	for(register int i = 2; i < n; i++) if(c[i] != b[2][i - 2]) return;
	ans.clear(); ans[b[1]] += 1; ans[b[2]] += 2;
	for(register int i = 3; i <= 2 * n - 2; i += 2) {
		int res1 = 0, res2 = 0, ok1 = 1, ok2 = 1;
		int len = b[i].size();
		for(register int j = 1; j <= len; j++) {
			if(c[j] != b[i][j - 1]) ok1 = 0;
			if(c[j] != b[i + 1][j - 1]) ok2 = 0;
		}
		if(ok1) res1++; if(ok2) res2++;
		ok1 = 1; ok2 = 1;
		for(register int j = n - len + 1, fir = 0; j <= n; j++, fir++) {
			if(c[j] != b[i][fir]) ok1 = 0;
			if(c[j] != b[i + 1][fir]) ok2 = 0;
		}
		if(ok1) res1 += 2; if(ok2) res2 += 2;
		if(!res1 || !res2) return;
		if(res1 < 3 && res1 == res2) return;
		if(res1 == 3) {
			if(res2 == 3) ans[b[i]] += 1, ans[b[i + 1]] += 2;
			else ans[b[i]] += 3 - res2, ans[b[i + 1]] += res2;
		} else {
			ans[b[i]] += res1; ans[b[i + 1]] += 3 - res1;
		}
//		cout << ans[b[i]] << " " << ans[b[i + 1]] << endl;
	}
	for(register int i = 1; i <= 2 * n - 2; i++) {
		if(ans[a[i]] == 1) cout << "P";
		if(ans[a[i]] == 2) cout << "S";
		if(ans[a[i]] == 3) cout << "P", ans[a[i]] = 2;
	}
	exit(0);
}

int main() {
	read(n);
	for(register int i = 1; i <= 2 * n - 2; i++) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 2 * n - 1, cmp); solve(); swap(b[1], b[2]); solve();
	return 0;
}