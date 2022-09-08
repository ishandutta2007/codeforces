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

vector <int> a, b, u, v;
vector <ll> ans;
ll in[N], out[N];
int n, m;

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        out[u] += w; in[v] += w;
    }
    for (int i = 1; i <= n; i++) {
        ll tmp = min(in[i], out[i]);
        in[i] -= tmp; out[i] -= tmp;
        if (in[i]) a.push_back(i);
        if (out[i]) b.push_back(i);
    }
    int now = 0;
    for (int i = 0; i < (int)a.size(); ) {
        ll tmp = min(in[a[i]], out[b[now]]);
        u.push_back(b[now]); v.push_back(a[i]); ans.push_back(tmp);
        in[a[i]] -= tmp; out[b[now]] -= tmp;
        if (!in[a[i]]) ++i;
        if (!out[b[now]]) ++now;
    }
    print((int)u.size(), '\n');
    for (int i = 0; i < (int)u.size(); i++) {
        print(u[i], ' ');
        print(v[i], ' ');
        print(ans[i], '\n');
    }
    return 0;
}