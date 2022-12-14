/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class ENearestOppositeParity {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;

        vector<int> a(n);
        vector<vector<int>> graph(n);
        vector<int> dist(n, -1);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = -1; j <= 1; j += 2) {
                int p = i + j * a[i];

                if (p < 0 || p >= n) {
                    continue;
                }

                if ((a[i] % 2) != (a[p] % 2)) {
                    dist[i] = 1;
                    q.push(i);
                } else {
                    graph[p].push_back(i);
                }
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto x : graph[u]) {
                if (dist[x] == -1) {
                    dist[x] = dist[u] + 1;
                    q.push(x);
                }
            }
        }

        for (auto x : dist) {
            out << x << " ";
        }
        out << endl;
    }
};


int main() {
    ENearestOppositeParity solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}