#include <bits/stdc++.h>
using namespace std;

multiset <int> w[100111];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                w[j].insert(s[j]);
            }
        }
        
        for (int i = 1; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                w[j].erase(w[j].find(s[j]));
            }
        }
        for (int i = 0; i < m; i++) {
            cout << char(*w[i].begin());
            w[i].clear();
        }
        cout << endl;
    }
}