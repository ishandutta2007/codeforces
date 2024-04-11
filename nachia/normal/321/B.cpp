#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N, M; scanf("%d%d", &N, &M);
        vector<UL> ATK, DEF;
        rep(i, N) {
            char c[4]; UL strength; scanf("%3s %d", c, &strength);
            if (c[0] == 'A') ATK.push_back(strength);
            else DEF.push_back(strength);
        }
        sort(ATK.begin(), ATK.end());
        sort(DEF.begin(), DEF.end());
        vector<UL> Ciel(M); rep(i, M) scanf("%d", &Ciel[i]);
        sort(Ciel.begin(), Ciel.end());

        UL ans = 0;
        {
            UL tmp = 0;
            vector<UL> F(M);
            UL pA, pD; pA = pD = 0;
            for (UL pow : Ciel) {
                UL opp = 0;
                if(pD != DEF.size())
                    if (DEF[pD] < pow) { pD++; continue; }
                if(pA != ATK.size())
                    if (ATK[pA] <= pow) { tmp += pow - ATK[pA]; pA++; continue; }
                tmp += pow;
            }
            if (pA == ATK.size() && pD == DEF.size()) ans = tmp;
        }
        {
            UL tmp = 0;
            reverse(Ciel.begin(), Ciel.end());
            for (UL i = 0; i < M; i++) {
                if (ATK.size() <= i) break;
                if (ATK[i] > Ciel[i]) break;
                tmp += Ciel[i] - ATK[i];
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}