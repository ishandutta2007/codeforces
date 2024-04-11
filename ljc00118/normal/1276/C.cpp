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

const int N = 4e5 + 5;

int a[N], b[N], cnt[N], s[N], c[N], tmp[N];
int n, big, maxn, ans;

vector <pii> qaq;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + big + 1, a[i]) - b, ++cnt[a[i]], ++s[cnt[a[i]]];
    for (int i = 1; i * i <= n; i++) {
        s[i] += s[i - 1];
        if (s[i] >= i * i && (s[i] / i) * i > maxn) {
            maxn = (s[i] / i) * i;
            ans = i;
        }
    }
    print(maxn, '\n');
    print(ans, ' '); print(maxn / ans, '\n');
    vector < vector <int> > res(ans + 1, vector <int> (maxn / ans + 1));
    int s = maxn;
    for (int id = 1; id <= big; id++) {
        int g = min(s, min(cnt[id], ans));
        qaq.push_back(make_pair(g, id));
        s -= g;
    }
    sort(qaq.begin(), qaq.end()); reverse(qaq.begin(), qaq.end());
    int y = 1, now = 0;
    for (int i = 0; i < (int)qaq.size(); i++) {
        for (int j = 0; j < (int)qaq[i].first; j++) {
            res[now + 1][(y + now - 1) % (maxn / ans) + 1] = b[qaq[i].second];
            if (now == ans - 1) {
                ++y; now = 0;
            } else {
                ++now;
            }
        }
    }
    for (int i = 1; i <= ans; i++) {
        for (int j = 1; j <= maxn / ans; j++) {
            print(res[i][j], ' ');
        }
        putchar('\n');
    }
    return 0;
}