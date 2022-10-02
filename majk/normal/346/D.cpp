#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<vector<int>> F(N);
    vector<int> O(N, 0);
    for (int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        --u; --v;
        O[u]++;
        F[v].push_back(u);
    }
    int S, T; cin >> S >> T;
    --S; --T;

    unordered_set<int> Dirty{T};
    int ans = 0;
    while (true) {
        if (Dirty.empty()) {
            cout << -1 << endl;
            return 0;
        }

        vector<int> Q;
        for (int d:Dirty) {
            Q.push_back(d);
            O[d] = 0;
        }
        Dirty.clear();

        for (int q = 0; q < Q.size(); ++q) {
            int u = Q[q];
            for (int v : F[u]) {
                if (O[v] == 0) continue;
                Dirty.insert(v);
                --O[v];
                if (O[v] == 0) {
                    Dirty.erase(v);
                    Q.push_back(v);
                    if (v == S) {
                        cout << ans << endl;
                        return 0;
                    }
                }
            }
        }

        ++ans;
        if (Dirty.find(S) != Dirty.end()) {
            cout << ans << endl;
            return 0;
        }
    }
}