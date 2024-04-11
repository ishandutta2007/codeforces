
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;
map<pair<int, int>, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int x = 0, y = 0;
        int l = -1, r = 1e9;
        m.clear();
        m[{0, 0}] = 0;
        for(int i = 1; i <= n; i++) {
            char c = s[i - 1];
            x += (c == 'R') - (c == 'L');
            y += (c == 'D') - (c == 'U');
            auto it = m.find({x, y});
            if(it != m.end()) {
                int j = it->second;
                if(i - j < r - l) {
                    l = j;
                    r = i;
                }
            }
            m[{x, y}] = i;
        }
        if(r == 1e9) {
            cout << -1 << endl;
        }else {
            cout << l + 1 << " " << r << endl;
        }
    }
}