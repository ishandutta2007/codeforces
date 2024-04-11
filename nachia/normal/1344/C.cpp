
#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    UL N, M;
    vector<UL> E[200000];
    vector<UL> rE[200000];
    bool F[200000] = {};
    bool rF[200000] = {};
    UL ans = 0;
    int I[200000] = {};

    void Solve() {
        scanf("%d%d", &N, &M);
        rep(i, M) {
            UL u, v; scanf("%d%d", &u, &v); u--; v--;
            E[u].push_back(v);
            rE[v].push_back(u);
            I[v]++;
        }
        queue<UL> Q; rep(i, N) if (I[i] == 0) Q.push(i);
        while (Q.size()) {
            UL p = Q.front(); Q.pop();
            for (UL e : E[p]) {
                I[e]--;
                if (I[e] == 0) Q.push(e);
            }
        }
        rep(i, N) if (I[i]) { cout << -1 << endl; return; }

        UL ans = 0;
        string ansS;
        rep(i, N) {
            if (F[i] || rF[i]) { ansS += "E"; }
            else{ ans++; ansS += "A"; }
            Q.push(i);
            while (Q.size()) {
                UL p = Q.front(); Q.pop();
                if (F[p]) continue;
                F[p] = true;
                for (UL e : E[p]) Q.push(e);
            }
            Q.push(i);
            while (Q.size()) {
                UL p = Q.front(); Q.pop();
                if (rF[p]) continue;
                rF[p] = true;
                for (UL e : rE[p]) Q.push(e);
            }
        }
        cout << ans << endl;
        cout << ansS << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}