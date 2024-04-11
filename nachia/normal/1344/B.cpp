#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct UF {
    UL N; vector<UL> V;
    UL SZ;
    void init(UL n) {
        N = n; V.resize(N);
        rep(i, N) V[i] = i;
        SZ = N;
    }
    UL root(UL a) {
        if (V[a] == a) return a;
        return(V[a] = root(V[a]));
    }
    void unite(UL a, UL b) {
        if (root(a) != root(b)) SZ--;
        V[root(a)] = root(b);
    }
};

struct Problem {

    UL H, W;
    bool G[1002][1002] = {};
    UF Q;

    void Solve() {
        scanf("%d%d", &H, &W);
        rep(y, H) rep(x, W) {
            char c; scanf(" %c", &c);
            G[x + 1][y + 1] = (c == '#');
        }

        int empR = 0;
        int empC = 0;
        rep(y, H) {
            int t = 0;
            rep(x, W) if (!G[x][y + 1] && G[x + 1][y + 1]) t++;
            if (t > 1) { cout << -1 << endl; return; }
            if (t == 0) empR++;
        }
        rep(x, W) {
            int t = 0;
            rep(y, H) if (!G[x + 1][y] && G[x + 1][y + 1]) t++;
            if (t > 1) { cout << -1 << endl; return; }
            if (t == 0) empC++;
        }

        if (empR == 0 && empC != 0) { cout << -1 << endl; return; }
        if (empR != 0 && empC == 0) { cout << -1 << endl; return; }

        Q.init(H + W);
        rep(y, H) {
            rep(x, W) {
                if (G[x + 1][y + 1]) {
                    Q.unite(x, y + W);
                }
            }
        }
        cout << (Q.SZ - empR - empC) << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}