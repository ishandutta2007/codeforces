/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

struct seq {
    int big, small, last;

    seq() : big(0), small(0), last(0) {}

    seq(int s) : big(s), small(s), last(s) {}

    seq operator+(const seq &o) const {
        seq ans;
        ans.big = max(big, last + o.big);
        ans.small = min(small, last + o.small);
        ans.last = last + o.last;
        return ans;
    }

    bool valid() {
        return small == 0 && last == 0;
    }

    int value() {
        if (valid()) return big;
        else return -1;
    }
};

struct segment_tree {
    vector<seq> st;

    segment_tree(int n) {
        st = vector<seq>(4 * n);
    }

    void update(int p, int b, int e, int x, int v) {
        if (b + 1 == e) {
            st[p] = seq(v);
        } else {
            int l = p << 1, r = l | 1, m = (b + e) >> 1;
            if (x < m) update(l, b, m, x, v);
            else update(r, m, e, x, v);
            st[p] = st[l] + st[r];
        }
    }

    int value() {
        return st[1].value();
    }
};

class EEditor {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;

        segment_tree st(n);

        string s;
        in >> s;

        int p = 0;

        for (auto x : s) {
            if (x == 'L') {
                p = max(p - 1, 0);
            } else if (x == 'R') {
                p++;
            } else if (x == '(') {
                st.update(1, 0, n, p, +1);
            } else if (x == ')') {
                st.update(1, 0, n, p, -1);
            } else {
                st.update(1, 0, n, p, 0);
            }

            out << st.value() << " ";
        }

        out << endl;
    }
};


int main() {
    EEditor solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}