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

vector <int> g;
ll res[13];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < (1 << 13); i++) if (__builtin_popcount(i) == 6) g.push_back(i);
	for (int i = 0; i < 13; i++) {
		vector <int> qry;
		for (int j = 0; j < n; j++) if ((g[j] >> i) & 1) qry.push_back(j + 1);
		if (qry.size() == 0) continue;
		cout << "? " << qry.size() << " ";
		for (int j = 0; j < (int)qry.size(); j++) cout << qry[j] << " ";
		cout << endl;
		cin >> res[i];
	}
	cout << "! ";
	for (int i = 0; i < n; i++) {
		ll ans = 0;
		for (int j = 0; j < 13; j++) if (((g[i] >> j) & 1) == 0) ans |= res[j];
		cout << ans << " ";
	}
	cout << endl;
    return 0;
}