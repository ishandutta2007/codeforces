#include <bits/stdc++.h>
using namespace std;

int t;
string s;
map<int, int> ma;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s;
        ma.clear();
        int cur = 0;
        for (char c : s) {
            if (c == '0') {
                ma[--cur]++;
            } else {
                ma[cur++]++;
            }
        }
        for (int cur = 0, i = 0; i < s.size(); i++) {
            if (ma[cur] == 0) {
                cout << 0;
                ma[--cur]--;
            } else if (ma[cur - 1] <= 1) {
                cout << 1;
                ma[cur++]--;
            } else {
                cout << 0;
                ma[--cur]--;
            }
        }
        cout << '\n';
    }
}