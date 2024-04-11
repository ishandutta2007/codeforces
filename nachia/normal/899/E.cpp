#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    struct Node {
        UL N;
        UL P;
        UL L, R;
        UL A;
        bool enable;
    };

    void Solve() {
        UL N; scanf("%d", &N);

        vector<Node> L;

        vector<UL> A(N); rep(i, N) scanf("%d", &A[i]);

        L.push_back({ 0, 0, (UL)-1, 1, 0, false });
        rep(i, N) {
            if (A[i] == L.back().A)
                L.back().N++;
            else
                L.push_back({ 1, i, (UL)L.size() - 1, (UL)L.size() + 1, A[i], true });
        }
        L.push_back({ 0, 0, (UL)L.size() - 1, (UL)-1, 0, false });

        auto cmp = [&L](const UL& l, const UL& r) ->bool {
            if (L[l].N != L[r].N) return L[l].N < L[r].N;
            return L[l].P > L[r].P;
        };
        priority_queue<UL, vector<UL>, decltype(cmp)> Q(cmp);
        rep(i, L.size()) Q.push(i);

        UL ans = 0;
        while (Q.size()) {
            UL p = Q.top(); Q.pop();
            if (!L[p].enable) continue;

            ans++; L[p].enable = false;
            UL l = L[p].L, r = L[p].R;
            if (L[l].A != 0 && L[l].A == L[r].A) {
                L[l].enable = L[r].enable = false;
                if (L[r].R != -1) L[L[r].R].L = L.size();
                if (L[l].L != -1) L[L[l].L].R = L.size();
                L.push_back({ L[l].N + L[r].N, L[l].P, L[l].L, L[r].R, L[l].A, true });
                Q.push(L.size() - 1);
            }
            L[l].R = r;
            L[r].L = l;
        }
        cout << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}