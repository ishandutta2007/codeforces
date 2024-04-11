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

const int N = 15;

int n, a[N];
 
int main() {
    read(n);
    for (int i = 0; i < n; i++) read(a[i]);
    for (int i = 0; i < (1 << n); i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            int o = (i >> j & 1) ? 1 : -1;
            c = (c + o * a[j] + 360) % 360;
        }
        if (!c) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}