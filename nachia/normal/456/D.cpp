#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {
    vector<vector<UL>> E;
    UL dfs(UL p, UL leaf) {
        if (E[p].empty()) return leaf;
        vector<UL> tmp;
        for (UL e : E[p]) tmp.push_back(dfs(e, leaf));
        UL mex = 0;
        sort(tmp.begin(), tmp.end());
        for(UL g : tmp) { if (g > mex) break; mex = g + 1; }
        return mex;
    }
    void Solve() {
        UL N, K; cin >> N >> K;
        vector<UL> P;
        vector<UL> st;
        {
            vector<map<char, UL>> V;
            V.push_back(map<char, UL>());
            rep(i, N) {
                string S; cin >> S;
                UL p = 0;
                for (char c : S) {
                    if (!V[p].count(c)) {
                        V[p][c] = V.size();
                        p = V.size();
                        V.push_back(map<char, UL>());
                    }
                    else {
                        p = V[p][c];
                    }
                }
            }
            E.resize(V.size());
            rep(i, V.size()) {
                for (auto p : V[i]) {
                    E[i].push_back(p.second);
                }
            }
        }
        bool FirstWin = dfs(0, 0) != 0;
        bool FirstLose = dfs(0, 1) != 0;
        if (FirstWin && FirstLose) { cout << "First" << endl; return; }
        if (!FirstWin) { cout << "Second" << endl; return; }
        if (K % 2) cout << "First" << endl;
        else cout << "Second" << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}