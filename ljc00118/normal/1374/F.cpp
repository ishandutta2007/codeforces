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

const int N = 505;

vector <int> ans;
int a[N], id[N], rk[N];
int T, n, rord;

bool cmp(int x, int y) { return a[x] < a[y]; }

void move(int x) {
	ans.push_back(x);
	swap(rk[x + 1], rk[x + 2]);
	swap(rk[x], rk[x + 1]);
}

int main() {
	read(T);
	while (T--) {
		read(n); rord = 0; ans.clear();
		for (int i = 1; i <= n; i++) read(a[i]), id[i] = i;
		sort(id + 1, id + n + 1, cmp);
		for (int i = 1; i <= n; i++) rk[id[i]] = i;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) if (rk[i] > rk[j]) ++rord;
		}
		if (rord & 1) {
			bool ok = 0;
			for (int i = 1; i < n; i++) {
				if (a[id[i]] == a[id[i + 1]]) {
					ok = 1;
					swap(rk[id[i]], rk[id[i + 1]]);
					break;
				}
			}
			if (!ok) {
				print(-1, '\n');
				continue;
			}
		}
		for (int i = n; i >= 1; i--) {
			int pos;
			for (int j = 1; j <= i; j++) {
				if (rk[j] == i) {
					pos = j;
					break;
				}
			}
			while (pos < i) {
				if (pos == 1) move(1);
				else move(pos - 1);
				++pos;
			}
		}
		print(ans.size(), '\n');
		for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
		putchar('\n');
	}
	return 0;
}