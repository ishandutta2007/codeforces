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

const int N = 3e5 + 5, INF = 1e9;

vector <int> pos[N];
int a[N], ans[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) pos[i].clear(), ans[i] = INF;
        for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]].push_back(i);
        for (int i = 1; i <= n; i++) {
            if (!pos[i].size()) continue;
            int maxn = pos[i][0];
            for (int j = 1; j < (int)pos[i].size(); j++) maxn = max(maxn, pos[i][j] - pos[i][j - 1]);
            maxn = max(maxn, n - pos[i][pos[i].size() - 1] + 1);
            if (ans[maxn] == INF) ans[maxn] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (i != 1) ans[i] = min(ans[i], ans[i - 1]);
            if (ans[i] == INF) print(-1, i == n ? '\n' : ' ');
            else print(ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}