#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include <algorithm>
#include <numeric>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<long long>> cost(3, vector<long long>(n));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> tree(n);

    for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int endpoint = 0;

    for (int i = 0; i < n; ++i) {
        if (tree[i].size() >= 3) {
            cout << -1 << endl;
            return 0;
        }

        if (tree[i].size() == 1) {
            endpoint = i;
        }
    }

    vector<int> path(n);

    int cur = endpoint, prev = -1;

    for (int i = 0; i < n; ++i) {
        path[i] = cur;

        for (auto x : tree[cur]) {
            if (x != prev) {
                prev = cur;
                cur = x;
                break;
            }
        }
    }

    long long answer = -1;

    vector<int> order(3);
    iota(order.begin(), order.end(), 0);

    vector<int> best;

    do {
        long long value = 0;

        for (int i = 0; i < n; ++i) {
            value += cost[order[i % 3]][path[i]];
        }
        
        if (answer == -1){
            answer = value;
            best = order;
        } else if (value < answer) {
            answer = value;
            best = order;
        }
    } while (next_permutation(order.begin(), order.end()));

    vector<int> solution(n);

    for (int i = 0; i < n; ++i) {
        solution[path[i]] = best[i % 3] + 1;
    }

    cout << answer << endl;

    for (int i = 0; i < n; ++i) {
        cout << solution[i] << " ";
    }

    cout << endl;

    return 0;
}