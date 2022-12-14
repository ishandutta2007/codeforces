/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class DRemoveOneElement {
    vector<int> get_inc(vector<int> &a) {
        vector<int> b(a.size(), 1);
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] > a[i - 1])
                b[i] = b[i - 1] + 1;
        }
        return b;
    }

public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (auto &x : a)
            in >> x;
        auto ri = get_inc(a);
        reverse(a.begin(), a.end());
        for (auto &x : a)
            x *= -1;
        auto le = get_inc(a);
        reverse(le.begin(), le.end());
        reverse(a.begin(), a.end());
        for (auto &x : a)
            x *= -1;

        int answer = ri[n - 1];

        for (int i = 1; i + 1 < n; ++i) {
            answer = max(answer, ri[i]);
            if (a[i - 1] < a[i + 1])
                answer = max(answer, ri[i - 1] + le[i + 1]);
        }

        out << answer << endl;
    }
};


int main() {
    DRemoveOneElement solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}