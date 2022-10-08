
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, k;
string s;
vector<pair<int, int>> ops;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        ops.clear();
        for(int i = 0; i < n; i++) {
            if((s[i] == '(') != (i % 2 == 0)) {
                int j = i + 1;
                for(; j < n; j++) {
                    if(s[j] != s[i]) break;
                }
                reverse(s.begin() + i, s.begin() + j + 1);
                ops.emplace_back(i, j);
            }
        }
        int d = n / 2, cnt = 0;
        for(int i = 0; i < n && d > k; i++) {
            cnt += (s[i] == '(') - (s[i] == ')');
            if(cnt == 0) {
                d--;
                reverse(s.begin() + i, s.begin() + i + 2);
                ops.emplace_back(i, i + 1);
                cnt = 2;
            }
        }
        cout << ops.size() << "\n";
        for(auto p : ops) {
            cout << p.first+1 << " " << p.second+1 << "\n";
        }
    }
}