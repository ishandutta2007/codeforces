#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> pos(n);
    vector<string> s(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int k;
        cin >> k;
        pos[i].resize(k);
        for (int& x : pos[i]) {
            cin >> x;
            --x;
        }
        len = max(len, pos[i].back() + (int)s[i].length());
    }
    string res(len, 'a');
    set<int> fp;
    for (int i = 0; i < len; i++)
        fp.insert(i);
    for (int i = 0; i < n; i++) {
        int m = s[i].length();
        for (int p : pos[i]) {
            auto it = fp.lower_bound(p);
            while (it != fp.end() && *it < p + m) {
                res[*it] = s[i][*it - p];
                auto go = it;
                ++go;
                fp.erase(it);
                it = go;
            }
        }
    }
    cout << res << "\n";
}