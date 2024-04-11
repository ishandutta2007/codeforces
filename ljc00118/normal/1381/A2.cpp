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

const int N = 1e5 + 5;

vector <int> ans;
char a[N], b[N];
int T, n;

int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s%s", a + 1, b + 1);
		ans.clear();
		int sum = 0, rev = 1;
		for (int i = n; i >= 1; i--) {
			// sum + rev * i = 1
			int pos = (1 - sum) * rev, cnt = (n - i) & 1;
			if (((int)a[pos] ^ cnt) == b[i]) ans.push_back(1);
			ans.push_back(i);
			sum = i + 1 - sum; rev *= -1;
		}
		print(ans.size(), ' ');
		for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
		putchar('\n');
	}
	return 0;
}