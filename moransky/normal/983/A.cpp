// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}
 
int main() {
    int T; read(T);
    while (T--) {
        LL p, q, b; read(p), read(q), read(b);
        q /= gcd(p, q);
        while (q > 1) {
            LL t = gcd(b, q);
            if (t == 1) break;
            while (q % t == 0) q /= t;
        }
        puts(q > 1 ? "Infinite" : "Finite");
    }
    return 0;
}