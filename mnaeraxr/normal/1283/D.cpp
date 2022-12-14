/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class DChristmasTrees {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;

        set<int> seen;
        queue<int> q;

        vector<int> tree;

        for (int i = 0; i < n; ++i) {
            int u;
            in >> u;
            seen.insert(u);
            tree.push_back(u);
            q.push(u + 1);
            q.push(u - 1);
        }

        vector<int> answer;

        while (answer.size() < m) {
            int u = q.front();
            q.pop();
            if (seen.find(u) != seen.end())
                continue;

            seen.insert(u);
            answer.push_back(u);
            q.push(u + 1);
            q.push(u - 1);
        }

        sort(tree.begin(), tree.end());

        long long tot = 0;

        for (auto x : answer) {
            auto p = lower_bound(tree.begin(), tree.end(), x) - tree.begin();

            int distance = m;

            if (p < n) distance = min(distance, tree[p] - x);
            if (p > 0) distance = min(distance, x - tree[p - 1]);

            tot += distance;
        }

        out << tot << endl;

        for (auto x : answer) {
            out << x << " ";
        }

        out << '\n';


    }
};


int main() {
    DChristmasTrees solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}