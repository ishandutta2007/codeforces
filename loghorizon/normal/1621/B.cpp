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

int n;

map<int, int> A, B;
map<PII, int> C;
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        int mn = 2e9, mx = -2e9;
        A.clear();
        B.clear();
        C.clear();
        while (n--) {
            int l, r, c;
            read(l), read(r), read(c);
            chkMax(mx, r);
            chkMin(mn, l);
            if (B.count(r)) chkMin(B[r], c);
            else B[r] = c;
            if (A.count(l)) chkMin(A[l], c);
            else A[l] = c;
            if (C.count(mp(l, r))) chkMin(C[mp(l, r)], c);
            else C[mp(l, r)] = c;
            int ans = B[mx] + A[mn];
            if (C.count(mp(mn, mx))) chkMin(ans, C[mp(mn, mx)]);
            printf("%d\n", ans);
        }
    }
    return 0;
}