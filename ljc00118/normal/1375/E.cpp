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

const int N = 1005;

vector <pii> ans, now;
int a[N], b[N];
int n;

void add(int x, int y) {
	swap(a[x], a[y]);
	ans.push_back(make_pair(x, y));	
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
	for (int i = 1; i <= n; i++) {
		now.clear();
		for (int j = i + 1; j <= n; j++) {
			if (b[i] > b[j]) {
				now.push_back(make_pair(b[j], j));
			}
		}
		sort(now.begin(), now.end());
		for (int j = (int)now.size() - 1; j >= 0; j--) add(i, now[j].second);
	}
	print((int)ans.size(), '\n');
	for (int i = 0; i < (int)ans.size(); i++) print(ans[i].first, ' '), print(ans[i].second, '\n');
	return 0;
}