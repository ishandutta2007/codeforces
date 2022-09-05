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

const int N = 1505;

bitset <N> f[N], all;
vector <int> ans;
int a[N][N], b[N][N], cando[N], used[N], id[N];
int n, m;

int ID;
bool cmp(int i, int j) {
    return a[i][ID] < a[j][ID];
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(b[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] <= b[i + 1][j]) f[i][j] = 1;
        }
    }
    while (1) {
        for (int i = 1; i <= m; i++) all[i] = 1;
        for (int i = 1; i < n; i++) {
            if (!cando[i]) {
                all &= f[i];
            }
        }
        int pos = 0;
        for (int i = 1; i <= m; i++) {
            if (all[i] && !used[i]) {
                pos = i;
                break;
            }
        }
        if (!pos) break;
        ans.push_back(pos);
        used[pos] = 1;
        for (int i = 1; i < n; i++) {
            if (b[i][pos] < b[i + 1][pos]) {
                cando[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) id[i] = i;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        ID = ans[i];
        stable_sort(id + 1, id + n + 1, cmp);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[id[i]][j] != b[i][j]) {
                print(-1, '\n');
                return 0;
            }
        }
    }
    print((int)ans.size(), '\n');
    for (auto i : ans) print(i, ' ');
    putchar('\n');
    return 0;
}