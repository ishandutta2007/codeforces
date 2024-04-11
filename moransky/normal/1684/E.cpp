// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, k, a[N], c[2][N], d[2][N], kb[N];

set<int> s;

void inline add(int o, int x, int y) {
    d[o][x] += y;
    for (; x <= n; x += x & -x) c[o][x] += y;
}

int get(int k) {
    int s = 0, t = 0, p = 0;
    for (int i = 17; i >= 0; i--) {
        if (p + (1 << i) <= n && s + c[1][p + (1 << i)] < k) {
            p += 1 << i;
            s += c[1][p];
            t += c[0][p];
        }
    }
    int o = p + 1;
    int le = min((k - s) / o, d[0][o]);
    t += le;
    return t;
}

int main() {
    int T; read(T);
    while (T--) {
        s.clear();
        read(n), read(k);
        int ans = 2e9;
        int co = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (!s.count(a[i])) s.insert(a[i]), co++;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 0; i <= n; i++) {
            if (!s.count(i)) kb[i] = 1;
            else kb[i] = 0;
            if (i >= 0) kb[i] += kb[i - 1];
        }
        for (int i = n, j = n; i >= 0; i--) {
            if (s.count(i)) continue;
            while (j >= 1 && a[j] >= i) {
                int k = j;
                while (k > 1 && a[k - 1] == a[j]) k--;
                int sz = j - k + 1;
                add(0, sz, 1);
                add(1, sz, sz);
                j = k - 1;
            }
            int tp = 0;
            if (i > 0) tp += kb[i - 1];
            if (k >= tp) {
                int js = get(k);
                int st = co - js - i + tp;
                if (i == 0 && st == 0) st = 1;
                chkMin(ans, st);
            }
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) c[0][i] = c[1][i] = d[0][i] = d[1][i] = 0;
    }   
    return 0;
}