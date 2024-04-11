#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 1e5 + 5, MAXN = 1e5;

stack <int> st;
vector <int> mug[N], g[N];
int cnt[N], c[N], a[N], mu[N], pri[N], isp[N];
int n, len, tot; ll ans;

void add(int x, int y) {
    for (int i = 0; i < (int)g[x].size(); i++) {
        cnt[g[x][i]] += y;
    }
}

int main() {
    mu[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (!isp[i]) { pri[++len] = i; mu[i] = -1; }
        for (int j = 1; j <= len && i * pri[j] <= MAXN; j++) {
            isp[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
            mu[i * pri[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= MAXN; i++) {
        if (mu[i]) {
            for (int j = i; j <= MAXN; j += i) g[j].push_back(i);
        }
    }
    read(n);
    for (int i = 1; i <= n; i++) {
        int x; read(x);
        c[x] = 1; ans = max(ans, (ll)x);
    }
    for (int d = 1; d <= MAXN; d++) {
        tot = 0;
        for (int i = d; i <= MAXN; i += d) if (c[i]) a[++tot] = i / d;
        while (!st.empty()) add(st.top(), -1), st.pop();
        for (int i = tot; i >= 1; i--) {
            int now = 0;
            for (int j = 0; j < (int)g[a[i]].size(); j++) {
                now += cnt[g[a[i]][j]] * mu[g[a[i]][j]];
            }
            int las = 0;
            while (now) {
                for (int j = 0; j < (int)g[st.top()].size(); j++) {
                    if (a[i] % g[st.top()][j] == 0) {
                        now -= mu[g[st.top()][j]];
                    }
                }
                add(st.top(), -1); las = st.top(); st.pop();
            }
            if (las) ans = max(ans, 1ll * a[i] * las * d);
            add(a[i], 1); st.push(a[i]);
        }
    }
    print(ans, '\n');
    return 0;
}