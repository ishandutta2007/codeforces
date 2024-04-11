
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n;
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            v.emplace_back(p[i], i);
        }
        sort(v.begin(), v.end());
        int m = n, M = -1;
        for(auto p : v) {
            m = min(m, p.second);
            M = max(M, p.second);
            cout << (M - m + 1 == p.first ? 1 : 0);
        }
        cout << endl;
    }
}