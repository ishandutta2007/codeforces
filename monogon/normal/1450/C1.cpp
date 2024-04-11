
#include <bits/stdc++.h>

using namespace std;

const int N = 305;
int n;
string s[N];

void solve() {
    cin >> n;
    // cnt[color] = occurrences of X on that color cell.
    int cnt[3] = {0, 0, 0};
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < n; j++) {
            if(s[i][j] == 'X') {
                cnt[(i + j) % 3]++;
            }
        }
    }
    // val = best color
    int val = min_element(cnt, cnt + 3) - cnt;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // flip tokens whose color is the best val
            if(s[i][j] == 'X' && (i + j) % 3 == val) {
                s[i][j] = 'O';
            }
        }
        cout << s[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}