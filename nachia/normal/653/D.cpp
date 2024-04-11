#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Edge { UL to; ULL cap; UL rev; UL id; };

struct Problem {

    UL N, M, X;
    vector<Edge> E[50];
    UL Cap[500];
    bool F[50];

    ULL DFS(UL p, ULL flow) {
        if (flow == 0) return 0;
        if (F[p]) return 0;
        if (p == N - 1) return flow;
        F[p] = true;
        ULL ans = 0;
        for (auto& e : E[p]) {
            ULL tmp = DFS(e.to, min(flow - ans, e.cap));
            e.cap -= tmp;
            E[e.to][e.rev].cap += tmp;
            ans += tmp;
        }
        return ans;
    }

    void Solve() {
        scanf("%d%d%d", &N, &M, &X);
        rep(i, M) {
            UL u, v, c; scanf("%d%d%d", &u, &v, &c); u--; v--;
            Cap[i] = c;
            E[u].push_back({ v, 0, E[v].size(), i });
            E[v].push_back({ u, 0, E[u].size() - 1, (UL)-1 });
        }
        double l = 0, r = 1e6;
        while (l + (1e-7 / X) < r && l * (1.0 + 1e-7) < r) {
            double m = (l + r) / 2.0;
            rep(u, N) for (auto& e : E[u]) {
                if (e.id == -1) e.cap = 0;
                else e.cap = Cap[e.id] / m;
            }

            UL ans = 0, tmp = 0;
            rep(i, N) F[i] = false;
            while (tmp = DFS(0, X - ans)) {
                rep(i, N) F[i] = false;
                ans += tmp;
            }
            if (ans == X) l = m; else r = m;
        }
        cout << (l * X) << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}