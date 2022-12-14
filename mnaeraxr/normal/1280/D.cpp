/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

const int long long oo = 0x3f3f3f3f3f3f3f3f;

pair<int, long long> merge(pair<int, long long> a, pair<int, long long> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

class DMissPunyverse {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;

        while (t--) {
            int n, m;
            in >> n >> m;

            vector<long long> w(n);

            for (int i = 0; i < n; ++i) {
                in >> w[i];
            }

            for (int i = 0; i < n; ++i) {
                long long v;
                in >> v;
                w[i] = v - w[i];
            }

            vector<vector<int>> tree(n);

            for (int i = 0; i + 1 < n; ++i) {
                int u, v;
                in >> u >> v;
                u--;
                v--;
                tree[u].push_back(v);
                tree[v].push_back(u);
            }

            vector<vector<pair<int, long long>>> A(n);
            vector<vector<pair<int, long long>>> B(n);

            function<int(int, int)> dfs = [&](int s, int p) {
                int total = 1;

                A[s] = {make_pair(0, w[s])};
                B[s] = {make_pair(0, -oo)};

                for (auto u : tree[s]) {
                    if (u == p) continue;

                    int cur = dfs(u, s);
                    int prev = total;

                    total += cur;

                    vector<pair<int, long long>> na(total, {0, -oo});

                    for (int i = 0; i < prev; ++i) {
                        for (int j = 0; j < cur; ++j) {
                            na[i + j] = max(na[i + j], merge(A[s][i], A[u][j]));
                            na[i + j + 1] = max(na[i + j + 1], merge(A[s][i], B[u][j + 1]));
                        }
                    }

                    A[s].swap(na);
                }

                for (int i = 0; i < total; ++i) {
                    B[s].push_back({A[s][i].first + (A[s][i].second > 0), 0});
                }

                return total;
            };

            dfs(0, -1);

            out << B[0][m].first << endl;
        }
    }
};


int main() {
    DMissPunyverse solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}