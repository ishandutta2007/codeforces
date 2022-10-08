
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// if everything is full and no cars can go to designated parking spot,
// output -1.
// otherwise, put any cars in parking spots and cycle everything around repeatedly.

const int N = 55;
int n, k;
int s[5][N];
vector<tuple<int, int, int>> moves;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 1, 5) {
        rep(j, 1, n + 1) {
            cin >> s[i][j];
        }
    }
    auto domove = [&](int i, int r1, int c1, int r2, int c2) {
        moves.emplace_back(i, r2, c2);
        s[r2][c2] = i;
        s[r1][c1] = 0;
    };
    rep(t, 0, 2 * n + 2) {
        // row 2 (1)
        rep(i, 1, n + 1) {
            if(s[2][i] != 0 && s[2][i] == s[1][i]) {
                domove(s[2][i], 2, i, 1, i);
            }else if(s[2][i] != 0) {
                if(i > 1 && s[2][i - 1] == 0) {
                    domove(s[2][i], 2, i, 2, i - 1);
                }else if(i == 1 && s[3][1] == 0) {
                    domove(s[2][i], 2, i, 3, 1);
                }
            }
        }
        // row 3 (4)
        for(int i = n; i >= 1; i--) {
            if(s[3][i] != 0 && s[3][i] == s[4][i]) {
                domove(s[3][i], 3, i, 4, i);
            }else if(s[3][i] != 0) {
                if(i < n && s[3][i + 1] == 0) {
                    domove(s[3][i], 3, i, 3, i + 1);
                }else if(i == n && s[2][n] == 0) {
                    domove(s[3][i], 3, i, 2, n);
                }
            }
        }
    }
    if(*max_element(s[2] + 1, s[2] + n + 1) > 0 || *max_element(s[3] + 1, s[3] + n + 1) > 0) {
        cout << "-1\n";
        return 0;
    }
    cout << sz(moves) << '\n';
    for(auto &p : moves) {
        int i, r, c;
        tie(i, r, c) = p;
        cout << i << ' ' << r << ' ' << c << '\n';
    }
}