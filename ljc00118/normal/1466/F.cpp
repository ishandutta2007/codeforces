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

const int N = 5e5 + 5, md = 1e9 + 7;

vector <int> res;
int f[N];
int n, m, ans = 1;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(n); read(m);
    for (int i = 1; i <= m + 1; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        int k, x, y; read(k);
        if (k == 1) read(x), y = m + 1;
        else read(x), read(y);
        if (find(x) != find(y)) {
            f[find(x)] = find(y);
            res.push_back(i);
        }
    }
    for (int i = 0; i < (int)res.size(); i++) ans = (ans + ans) % md;
    print(ans, ' '); print(res.size(), '\n');
    for (auto i : res) print(i, ' ');
    putchar('\n');
    return 0;
}