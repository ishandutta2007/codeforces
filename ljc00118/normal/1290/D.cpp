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

const int N = 1024;

int ans[N];
int n, k, sum;

int ask(int x) {
	cout << "? " << x + 1 << endl;
	char ans; cin >> ans; return ans == 'Y';
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) ans[i] = 1;
	for (int s = 0; s < n / k; s++) {
		int det = 0;
		cout << "R" << endl;
		for (int _ = 0; _ < n / k; _++) {
			int now = (s + det + (n / k)) % (n / k);
			for (int i = now * k; i < (now + 1) * k; i++) {
				if (ans[i] && ask(i)) ans[i] = 0;
			}
			if (det >= 0) ++det;
			det = -det;
		}
	}
	for (int i = 0; i < n; i++) sum += ans[i];
	cout << "! " << sum << endl;
    return 0;
}