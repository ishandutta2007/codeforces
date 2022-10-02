#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> E;

// 1 - one line
// 2 - two lines
// 3 - two lines on one side
// 4 - two lines on both sides and can go across
// 5 - two lines on both sides and cannot go across
// 6 - two lines on both sides and one side blocked
// 7 - two lines on both sides and both sides blocked
// 0 - impossible
int dfs(int u, int p) {
    vector<int> cnt(8, 0); 
    for (int v:E[u]) if (v != p) {
        int g = dfs(v,u);
        // cout << v+1 << ' ' << u+1 << ' ' << g << endl;
        cnt[g]++;
    }
    bool needsSide = cnt[3] > 0 || cnt[2] > 0 || cnt[1] >= 3;
    if (cnt[0] || cnt[7] > 0 || (cnt[6] > 0 && cnt[1] >= 2) || cnt[4] >= 2 || (cnt[4] == 1 && needsSide) || cnt[3] >= 3) return 0;
    if ((cnt[6] && cnt[1]) || (cnt[4] == 1 && cnt[1] == 2)) return 7;
    if (cnt[6] || cnt[5] || (cnt[4] == 1 && cnt[1] == 1)) return 6;
    if (cnt[4] == 1) return 5;
    if (cnt[3] == 2) return 4;
    if (needsSide) return 3;
    if (cnt[1] == 2) return 2;
    return 1;
}

int main() {
    int N; cin >> N;
    E.resize(N);
    for (int i = 0; i < N-1; ++i) {
        int u,v; cin >> u >> v;
        --u; --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int ans = dfs(0, -1);
    cout << (ans == 0 ? "No" : "Yes") << endl;

}