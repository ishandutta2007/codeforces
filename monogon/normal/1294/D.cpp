
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 4e5 + 5;
int q, x, y;
int val[N];
set<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q >> x;
    for(int i = 0; i < x; i++) {
        s.emplace(0, i);
    }
    while(q--) {
        cin >> y;
        y %= x;
        s.erase(make_pair(val[y]++, y));
        s.emplace(make_pair(val[y], y));
        auto p = *s.begin();
        cout << (x * p.first + p.second) << endl;
    }
}