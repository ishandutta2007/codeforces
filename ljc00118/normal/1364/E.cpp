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

const int N = 2050;

int ans[N], b[15];
int n;

int query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	int ans; cin >> ans; return ans;
}

int getnum(int id) {
	int ans = 0;
	for (int i = 0; i < 11; i++) {
		if (b[i] == id) continue;
		ans |= (query(id, b[i]) & (1 << i));
	}
	return ans;
}

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	cin >> n;
	int cnt = 0;
	while (cnt < 11) {
		int x = rand() % n + 1, y = rand() % n + 1;
		while (x == y) x = rand() % n + 1, y = rand() % n + 1;
		int v = query(x, y);
		for (int i = 0; i < 11; i++) {
			if (!b[i] && ((v >> i) & 1) == 0) {
				b[i] = x; ++cnt;
			}
		}
	}
	int minn = getnum(1), pos = 1;
	for (int i = 2; i <= n; i++) {
		if (!minn) break;
		if ((query(i, pos) | minn) == minn) minn = getnum(i), pos = i;
	}
	for (int i = 1; i <= n; i++) {
		if (i == pos) continue;
		ans[i] = query(i, pos);
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) cout<< ans[i] << " ";
	cout << endl;
	return 0;
}