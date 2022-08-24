#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    string s;
    cin >> s;
    vector<pair<int,int>> cands;
    int x = 0;
    int y = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            x++;
        }
        else if (s[i] == 'L') {
            x--;
        }
        else if (s[i] == 'U') {
            y++;
        }
        else {
            y--;
        }
        if (x != 0 || y != 0) cands.emplace_back(x, y);
    }
    int xx = 0;
    int yy = 0;
    for (auto& it : cands) {
        int curx = 0;
        int cury = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                curx++;
            }
            else if (s[i] == 'L') {
                curx--;
            }
            else if (s[i] == 'U') {
                cury++;
            }
            else {
                cury--;
            }
            if (curx == it.first && cury == it.second) {
                if (s[i] == 'R') {
                    curx--;
                }
                else if (s[i] == 'L') {
                    curx++;
                }
                else if (s[i] == 'U') {
                    cury--;
                }
                else {
                    cury++;
                }
            }
        }
        if (curx == 0 && cury == 0) {
            xx = it.first; yy = it.second;
        }
    }
    cout << xx << " " << yy << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}