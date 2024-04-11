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

LL n;

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        n *= 2;
        LL o = n, p = 1;
        while (o % 2 == 0) o /= 2, p *= 2;
        if (o == 1) puts("-1");
        else {
            if (p > o) swap(p, o);
            LL k = p;
            printf("%lld\n", k);
        }   
    }
    return 0;
}