#include <bits/stdc++.h>
using namespace std;

const int LG = 60;

int n;
long long u;
list<long long> li;
vector<long long> ve[LG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> u;
        ve[__lg(u)].push_back(u);
    }
    for (int i = LG - 1; i >= 0; i--) {
        int pt = 0;
        for (auto it = li.begin(); it != li.end(); it = next(it)) {
            if (((*it) >> i & 1) && pt < ve[i].size()) {
                li.insert(it, ve[i][pt++]);
            }
        }
        if (pt < ve[i].size()) {
            li.push_back(ve[i][pt++]);
        }
        if (pt < ve[i].size()) {
            return cout << "No", 0;
        }
    }
    cout << "Yes\n";
    for (long long &v : li) {
        cout << v << " ";
    }
}