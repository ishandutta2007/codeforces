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

const int N = 1e5 + 5;

vector <int> g[N];
int isp[N], las[N], r[N], a[N], go[N][18];
int n, q;

int main() {
    for (int i = 2; i <= 100000; i++) {
        if (isp[i]) continue;
        for (int j = i; j <= 100000; j += i) {
            g[j].push_back(i);
            isp[j] = 1;
        }
    }
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    r[n + 1] = n;
    for (int i = n; i >= 1; i--) {
        r[i] = r[i + 1];
        for (int j = 0; j < (int)g[a[i]].size(); j++) {
            int x = g[a[i]][j];
            if (las[x]) r[i] = min(r[i], las[x] - 1);
        }
        for (int j = 0; j < (int)g[a[i]].size(); j++) {
            int x = g[a[i]][j];
            las[x] = i;
        }
    }
    for (int i = 0; i <= 17; i++) go[n + 1][i] = n + 1;
    for (int i = n; i >= 1; i--) {
        go[i][0] = r[i] + 1;
        for (int j = 1; j <= 17; j++) {
            go[i][j] = go[go[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int l, r;
        read(l); read(r);
        int ans = 0;
        for (int i = 17; i >= 0; i--) {
            if (go[l][i] <= r) {
                ans += (1 << i);
                l = go[l][i];
            }
        }
        print(ans + 1, '\n');
    }
    return 0;
}