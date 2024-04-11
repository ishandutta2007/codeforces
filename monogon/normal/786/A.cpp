
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

// -1 = win
// 0 = lose
// > 0 => loop

const int N = 7005;
int n, k[2], s[2][N], ans[2][N];
bool vis[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(l, 0, 2) {
        cin >> k[l];
        rep(i, 0, k[l]) {
            cin >> s[l][i];
        }
    }
    queue<pii> Q;
    rep(l, 0, 2) rep(i, 0, n) {
        ans[l][i] = k[l];
    }
    ans[0][0] = ans[1][0] = 0;
    Q.emplace(0, 0);
    Q.emplace(1, 0);
    vis[0][0] = vis[1][0] = true;
    while(!Q.empty()) {
        int l, i;
        tie(l, i) = Q.front(); Q.pop();
        rep(j, 0, k[!l]) {
            int idx = (i - s[!l][j] + n) % n;
            if(ans[l][i] == -1 && ans[!l][idx] > 0 && !vis[!l][idx]) {
                ans[!l][idx]--;
                if(ans[!l][idx] == 0) {
                    vis[!l][idx] = true;
                    Q.emplace(!l, idx);
                }
            }else if(ans[l][i] == 0 && !vis[!l][idx]) {
                ans[!l][idx] = -1;
                vis[!l][idx] = true;
                Q.emplace(!l, idx);
            }
        }
    }
    rep(l, 0, 2) {
        rep(i, 1, n) {
            switch(ans[l][i]) {
            case 0: cout << "Lose "; break;
            case -1: cout << "Win "; break;
            default: cout << "Loop "; break;
            }
        }
        cout << '\n';
    }
}