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

int a, b, c, ab, ac, bc, abc;
int T, a1, b1, c1, a2, b2, c2, pa, pb, pc, pab, pac, pbc, pabc, ca, cb, cc;

int main() {
    read(T);
    while (T--) {
        read(a1); read(b1); read(c1); read(a2); read(b2); read(c2);
        read(pabc); read(pab); read(pac); read(pa); read(pbc); read(pb); read(pc);
        ca = pabc + pab + pac + pa; cb = pabc + pab + pbc + pb; cc = pabc + pac + pbc + pc;
        if (ca > a1 + a2 || cb > b1 + b2 || cc > c1 + c2) {
            print(-1, '\n');
            continue;
        }
        bool ok = 0;
        for (abc = 0; abc <= pabc; abc++) {
            for (ac = 0; ac <= pac; ac++) {
                int _a1 = a1 - abc - ac, _b1 = b1 - abc, _c1 = c1 - abc - ac;
                int _a2 = a2 - (pabc - abc) - (pac - ac), _b2 = b2 - (pabc - abc), _c2 = c2 - (pabc - abc) - (pac - ac);
                if (_a1 < 0 || _b1 < 0 || _c1 < 0 || _a2 < 0 || _b2 < 0 || _c2 < 0) continue;
                for (int iab = 0; iab <= 2; iab++) {
                    for (int ibc = 0; ibc <= 2; ibc++) {
                        for (int iabc = 0; iabc <= 2; iabc++) {
                            if ((iab > 0) + (ibc > 0) + (iabc > 0) == 2) {
                                int _ = 0;
                                if (iab == 1) ab = max(pab - _a2, 0);
                                if (iab == 2) ab = min(_a1, pab);
                                if (ibc == 1) bc = max(pbc - _c2, 0);
                                if (ibc == 2) bc = min(_c1, pbc);
                                if (iabc == 1) _ = max(pab + pbc - _b2, 0);
                                if (iabc == 2) _ = min(_b1, pab + pbc);
                                if (iab && ibc) {
                                    if (max(pab + pbc - _b2, 0) <= ab + bc && ab + bc <= min(_b1, pab + pbc)) {
                                        ok = 1;
                                        break;
                                    }
                                }
                                if (iab && iabc) {
                                    bc = _ - ab;
                                    if (max(pbc - _c2, 0) <= bc && bc <= min(_c1, pbc)) {
                                        ok = 1;
                                        break;
                                    }
                                }
                                if (ibc && iabc) {
                                    ab = _ - bc;
                                    if (max(pab - _a2, 0) <= ab && ab <= min(_a1, pab)) {
                                        ok = 1;
                                        break;
                                    }
                                }
                            }
                        }
                        if (ok) break;
                    }
                    if (ok) break;
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) {
            a1 -= (abc + ab + ac); b1 -= (abc + ab + bc); c1 -= (abc + ac + bc);
            print(abc, ' '); print(ab, ' '); print(ac, ' '); print(min(a1, pa), ' '); print(bc, ' '); print(min(b1, pb), ' '); print(min(c1, pc), '\n');
        } else {
            print(-1, '\n');
        }
    }
    return 0;
}