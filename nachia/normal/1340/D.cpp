#include <bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    UL N;
    UL M;
    vector<vector<UL>> E;
    vector<pair<UL, UL>> ans;
    vector<UL> P;

    void DFS(UL p, UL t) {
        ans.push_back({ p,t });
        UL G = E[p].size();
        if (t >= E[p].size()) {
            G = t;
            t -= E[p].size();
            ans.push_back({ p, t });
        }
        for (UL e : E[p]) {
            if (P[p] == e) continue;
            P[e] = p;
            if (t == G) {
                t -= E[p].size();
                ans.push_back({ p, t });
            }
            t++;
            DFS(e, t);
            ans.push_back({ p, t });
        }
        if (t == G) {
            t -= E[p].size();
            ans.push_back({ p, t });
        }
    }

    void Solve() {
        scanf("%d", &N);
        if (N == 1) { cout << "1\n1 0\n"; return; }

        E.resize(N);
        rep(i, N - 1) {
            UL u, v; scanf("%d%d", &u, &v); u--; v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        M = 0; rep(i, N) M = max(M, (UL)E[i].size());
        P.assign(N, -1);
        DFS(0, 0);
        ans.pop_back();
        cout << ans.size() << endl;
        for (auto p : ans) {
            printf("%d %d\n", p.first + 1, p.second);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}