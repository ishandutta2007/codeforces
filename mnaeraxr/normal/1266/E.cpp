/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class ESpaceshipSolitaire {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;

        vector<long long> a(n);
        vector<long long> b(n);

        long long answer = 0;

        for (int i = 0; i < n; ++i) {
            in >> a[i];
            answer += a[i];
        }


        vector<map<int, int>> milestone(n);

        int q;
        in >> q;

        while (q--) {
            int u, v, w;
            in >> u >> v >> w;
            u--;
            w--;

            if (milestone[u].find(v) != milestone[u].end()) {
                int nw = milestone[u][v];
                b[nw]--;
                if (b[nw] < a[nw]) {
                    answer++;
                }

                milestone[u].erase(v);
            }

            if (w != -1) {
                milestone[u][v] = w;
                b[w]++;
                if (b[w] <= a[w]) answer--;
            }

            out << answer << '\n';
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ESpaceshipSolitaire solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}