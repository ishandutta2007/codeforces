
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, r, a, b;
vector<pair<int, int> > inc, d;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(b >= 0) {
            inc.push_back({a, b});
        }else {
            d.push_back({max(a, -b) + b, b});
        }
    }
    sort(inc.begin(), inc.end());
    sort(d.begin(), d.end());
    for(auto p : inc) {
        if(r < p.first) {
            cout << "NO" << endl;
            return 0;
        }
        r += p.second;
    }
    int len = d.size();
    for(int i = len - 1; i >= 0; i--) {
        if(r < d[i].first - d[i].second) {
            cout << "NO" << endl;
            return 0;
        }
        r += d[i].second;
    }
    cout << "YES" << endl;
}