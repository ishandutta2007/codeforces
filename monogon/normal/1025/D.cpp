
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

// dp1[l][r]: is it possible for node [r] to be the root of a BST with nodes [l, r]?
// dp2[l][r]: is it possible for node [l] to be the root ... [l, r]

// is it possible for node i to be root of [l, r]? dp1[l][i] && dp2[i][r]
// overall, O(n^3)

const int N = 705;
int n;
ll a[N];
bool mat[N][N], dp1[N][N], dp2[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) rep(j, 0, n) {
        mat[i][j] = (gcd(a[i], a[j]) > 1);
    }
    rep(len, 1, n + 1) rep(l, 0, n - len + 1) {
        int r = l + len - 1;
        if(len == 1) {
            dp1[l][r] = dp2[l][r] = true;
        }else {
            rep(i, l, l + len) {
                if(mat[r][i] && i != r && dp1[l][i] && dp2[i][r - 1]) {
                    dp1[l][r] = true;
                }
                if(mat[l][i] && i != l && dp1[l + 1][i] && dp2[i][r]) {
                    dp2[l][r] = true;
                }
            }
        }
    }
    rep(i, 0, n) {
        if(dp1[0][i] && dp2[i][n - 1]) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}