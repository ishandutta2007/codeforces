#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 55;

queue <int> q;
int a[N][N], id[N][N], now[N], match[N], pre[N];
int T, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        cout << 'B' << endl;
        char foo; int s; cin >> foo >> s;
        if (s > n) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    swap(a[i][j], a[j][i]);
                }
            }
        }
        if (foo == 'I') {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    a[i][j] = n * n - a[i][j] + 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            static int t[N];
            for (int j = 1; j <= n; j++) t[j] = a[i][j];
            sort(t + 1, t + n + 1);
            for (int j = 1; j <= n; j++) id[i][n - (lower_bound(t + 1, t + n + 1, a[i][j]) - t) + 1] = j;
        }
        for (int i = 1; i <= n; i++) now[i] = 1, match[i] = 0, q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int v = id[u][now[u]]; ++now[u];
            if (!match[v] || a[u][v] < a[match[v]][v]) {
                if (match[v]) q.push(match[v]);
                match[v] = u;
            } else q.push(u);
        }
        for (int i = 1; i <= n; i++) pre[match[i]] = i;
        int flag = (s <= n);
        if (!flag) s -= n;
        while (1) {
            cout << pre[s] + flag * n << endl;
            cin >> s;
            if (s == -1) break;
            if (!flag) s -= n;
        }
    }
    return 0;
}