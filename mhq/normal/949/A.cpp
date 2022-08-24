#include <bits/stdc++.h>
using namespace std;
string s;
vector < vector < int > > t;
set < int > ones;
set < int > zeros;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') zeros.insert(i);
        else ones.insert(i);
    }
    while (!zeros.empty()) {
        vector < int > cur;
        auto it = zeros.begin();
        int x = *it;
        zeros.erase(it);
        cur.push_back(x);
        int clr = 0;
        int cr = x;
        while (1) {
            if (clr == 0) {
                auto it = ones.lower_bound(cr);
                if (it == ones.end()) break;
                else {
                    int y = *it;
                    ones.erase(it);
                    cur.push_back(y);
                    clr ^= 1;
                    cr = y;
                }
            }
            else {
                auto it = zeros.lower_bound(cr);
                if (it == zeros.end()) break;
                else {
                    int y = *it;
                    zeros.erase(it);
                    cur.push_back(y);
                    clr ^= 1;
                    cr = y;
                }
            }
        }
        if (cur.size() % 2 == 0) {
            int x = cur.back();
            ones.insert(x);
        }
        t.push_back(cur);
    }
    if (!ones.empty()) {
        cout << "-1";
        return 0;
    }
    cout << t.size() << '\n';
    for (int i = 0; i < t.size(); i++) {
        cout << t[i].size() << " ";
        for (int j = 0; j < t[i].size(); j++) cout << t[i][j] + 1 << " ";
        cout << '\n';
    }
    return 0;
}