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
 
int n = 1e5, pr[N], t;

bool st[N];

int main() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            pr[++t] = i;
            for (int j = i; j <= n; j += i) st[j] = 1;
        }
    }
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) printf("%d ", pr[i]);
        puts("");
    }
    return 0;
}