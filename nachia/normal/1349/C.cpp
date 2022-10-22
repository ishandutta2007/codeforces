#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

LL GCD(LL a, LL b) {
    return b ? GCD(b, a % b) : a;
}
LL LCM(LL a, LL b) {
    int g = GCD(a, b);
    return a / g * b;
}

struct Problem{


    UL H, W, T;
    UL G[1000][1000];
    UL D[1000][1000];
    bool F[1000][1000] = {};
    struct { UL y, x; ULL t; } Q[100000];

    void Solve() {
        scanf("%d%d%d", &H, &W, &T);
        rep(y, H) rep(x, W) {
            char c;
            scanf(" %c", &c);
            G[x][y] = (c - '0');
        }
        queue<pair<UL, UL>> S;
        rep(x, W) rep(y, H) {
            D[x][y] = 10000000;
            bool ok = false;
            if (x != 0) if (G[x - 1][y] == G[x][y]) ok = true;
            if (x != W - 1) if (G[x + 1][y] == G[x][y]) ok = true;
            if (y != 0) if (G[x][y - 1] == G[x][y]) ok = true;
            if (y != H - 1) if (G[x][y + 1] == G[x][y]) ok = true;
            if (ok) { D[x][y] = 0; S.push({ x, y }); }
        }
        while (S.size()) {
            UL x = S.front().first, y = S.front().second;
            S.pop();
            if (F[x][y]) continue;
            F[x][y] = true;
            UL d = D[x][y] + 1;
            if (x != 0) { D[x - 1][y] = min(D[x - 1][y], d); S.push({ x - 1, y }); }
            if (x != W - 1) { D[x + 1][y] = min(D[x + 1][y], d); S.push({ x + 1, y }); }
            if (y != 0) { D[x][y - 1] = min(D[x][y - 1], d); S.push({ x, y - 1 }); }
            if (y != H - 1) { D[x][y + 1] = min(D[x][y + 1], d); S.push({ x, y + 1 }); }
        }

        rep(i, T) {
            UL x, y; ULL t;
            scanf("%d%d%lld", &y, &x, &t);
            x--; y--;
            UL ans = 0;
            if (D[x][y] == 10000000) ans = G[x][y];
            else if (D[x][y] > t) ans = G[x][y];
            else {
                 ans = (G[x][y] + (t - D[x][y])) % 2;
            }
            printf("%d\n", ans);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}