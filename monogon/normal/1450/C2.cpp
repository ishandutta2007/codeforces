
#include <bits/stdc++.h>

using namespace std;

const int N = 305;
int te, n;
string s[N];

void solve() {
    cin >> n;
    // Let X = 0, O = 1. Let cnt[r][b] = the number of tokens b in diagonals with label r.
    int cnt[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int k = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < n; j++) {
            char c = s[i][j];
            int val = (i + j) % 3;
            if(c == 'X') {
                cnt[val][0]++;
                k++;
            }
            else if(c == 'O') {
                cnt[val][1]++;
                k++;
            }
        }
    }
    // Choose one diagonal label d to become all O's, and another diagonal label d2 to become all X's.
    for(int d = 0; d < 3; d++) {
        for(int d2 = 0; d2 < 3; d2++) {
            if(d == d2) continue;
            if(cnt[d][0] + cnt[d2][1] <= k / 3) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if((i + j) % 3 == d && s[i][j] == 'X') {
                            s[i][j] = 'O';
                        }else if((i + j) % 3 == d2 && s[i][j] == 'O') {
                            s[i][j] = 'X';
                        }
                    }
                    cout << s[i] << '\n';
                }
                return;
            }
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> te;
    while(te--) {
        solve();
    }
}