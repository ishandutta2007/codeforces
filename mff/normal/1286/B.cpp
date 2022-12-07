#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> graph(n);
    vector<int> w(n);
    int root = -1;

    for (int i = 0; i < n; ++i) {
        int p; cin >> p >> w[i];
        p--;
        if (p >= 0) graph[p].push_back(i);
        else root = i;
    }

    vector<int> id(n);

    function<void(int, int)> increase = [&](int s, int l) {
        if (id[s] >= l) ++id[s];
        for (auto u : graph[s])
            increase(u, l);
    };

    function<int(int, int)> solve = [&](int s, int l) {
        // cout << s << " " << l << endl;
        int sz = 0;
        int x = l;

        for (auto u : graph[s]) {
            int cur = solve(u, x);
            sz += cur;
            x += cur;
        }

        if (w[s] > sz) {
            cout << "NO" << endl;
            exit(0);
        }

        increase(s, l + w[s]);
        id[s] = l + w[s];
        // cout << s << " " << l << " "<< w[s] << endl;

        return sz + 1;
    };

    solve(root, 1);

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << id[i] << " \n"[i + 1 == n];
    }

    return 0;
}