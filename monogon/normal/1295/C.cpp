
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n, m;
string s, t;
vector<int> v[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> s >> t;
        n = s.length(); m = t.length();
        for(int i = 0; i < 26; i++) v[i].clear();
        for(int i = 0; i < n; i++) {
            v[s[i] - 'a'].push_back(i);
        }
        int x = 0, cost = 1;
        for(int i = 0; i < m; i++) {
            int j = t[i] - 'a';
            if(v[j].empty()) {
                cout << -1 << endl;
                goto endloop;
            }
            auto it = lower_bound(v[j].begin(), v[j].end(), x);
            if(it == v[j].end()) {
                it = v[j].begin();
                cost++;
            }
            x = *it + 1;
            if(x == n && i < m - 1) {
                x = 0;
                cost++;
            }
        }
        cout << cost << endl;
        endloop:;
    }
}