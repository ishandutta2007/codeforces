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

int main() {
    int T; read(T);
    while (T--) {
        int n; read(n);
        vector<int> w;
        while (n) w.pb(n % 10), n /= 10;
        if (w.size() == 2) printf("%d\n", w[0]);
        else {
            int mn = 2e9;
            for (int v: w) chkMin(mn, v);
            printf("%d\n", mn);
        }
    }
    return 0;
}