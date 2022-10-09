
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> right(n, vector<bool>(m)), down(n, vector<bool>(m));
    int cntE = 0, cntN = 0;
    rep(i, 0, n) {
        string s;
        cin >> s;
        // length m - 1
        rep(j, 0, m - 1) {
            right[i][j] = (s[j] == 'E');
            if(s[j] == 'E') cntE++;
            else cntN++;
        }
        if(i < n - 1) {
            cin >> s;
            // length m
            rep(j, 0, m) {
                down[i][j] = (s[j] == 'E');
                if(s[j] == 'E') cntE++;
                else cntN++;
            }
        }
    }
    if(k == 1) {
        if(cntN * 4 <= cntE + cntN) {
            cout << "YES\n";
            rep(i, 0, n) {
                rep(j, 0, m) {
                    cout << 1 << ' ';
                }
                cout << "\n";
            }
        }else {
            cout << "NO\n";
        }
        return 0;
    }
    auto check = [&](bool sw) {
        vector<vi> grid(n, vi(m, 1));
        int cnt = 0;
        rep(i, 0, n) {
            rep(j, 0, m - 1) {
                grid[i][j + 1] = (right[i][j] ? grid[i][j] : 3 ^ grid[i][j]);
            }
        }
        rep(i, 1, n) {
            int cnt0 = 0, cnt1 = 0;
            rep(j, 0, m) {
                if(down[i - 1][j] == (grid[i][j] == grid[i - 1][j])) {
                    cnt1++;
                }else {
                    cnt0++;
                }
            }

            cnt += min(cnt0, cnt1);
            if(cnt1 < cnt0) {
                rep(j, 0, m) grid[i][j] ^= 3;
            }
        }

        if(cnt * 4 <= (n - 1) * m + n * (m - 1)) {
            cout << "YES\n";
            if(sw) {
                rep(j, 0, m) {
                    rep(i, 0, n) {
                        cout << grid[i][j] << ' ';
                    }
                    cout << '\n';
                }
            }else {
                rep(i, 0, n) {
                    rep(j, 0, m) {
                        cout << grid[i][j] << ' ';
                    }
                    cout << '\n';
                }
            }
            exit(0);
        }
    };
    check(false);
    vector<vector<bool>> right2(m, vector<bool>(n)), down2(m, vector<bool>(n));
    rep(i, 0, n) rep(j, 0, m) {
        right2[j][i] = down[i][j];
        down2[j][i] = right[i][j];
    }
    swap(n, m);
    right2.swap(right);
    down2.swap(down);
    check(true);
    assert(false);
}