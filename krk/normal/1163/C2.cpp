#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1005;

struct pos {
    int A, B, C;
    bool operator<(const pos &u) const {
        if (A != u.A) return A < u.A;
        if (B != u.B) return B < u.B;
        return C < u.C;
    }
};

int n;
int X[Maxn], Y[Maxn];
set <pos> S;
map <ii, int> M;
int tot;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        for (int j = 0; j < i; j++) {
            int A = Y[i] - Y[j], B = X[j] - X[i];
            int C = X[i] * A + Y[i] * B;
            if (A < 0) { A = -A; B = -B; C = -C; }
            else if (A == 0)
                if (B < 0) { B = -B; C = -C; }
                else if (B == 0)
                    if (C < 0) C = -C;
            if (A == 0)
                if (B == 0) C = 1;
                else {
                    int g = gcd(abs(B), abs(C));
                    B /= g; C /= g;
                }
            else if (B == 0) {
                int g = gcd(abs(A), abs(C));
                A /= g; C /= g;
            } else {
                int g = gcd(gcd(abs(A), abs(B)), abs(C));
                A /= g; B /= g; C /= g;
            }
            pos p = {A, B, C};
            if (S.find(p) == S.end()) {
                S.insert(p);
                int g = gcd(abs(A), abs(B));
                A /= g; B /= g;
                M[ii(A, B)]++;
                tot++;
            }
        }
    }
    ll res = ll(tot) * (tot - 1) / 2;
    for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++)
        res -= ll(it->second) * (it->second - 1) / 2;
    printf("%I64d\n", res);
    return 0;
}