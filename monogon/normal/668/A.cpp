
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

const int N = 105, NIL = INT_MAX;
int n, m, q;
int ans[N][N], mat[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    rep(i, 0, n) {
        rep(j, 0, m) {
            mat[i][j] = m * i + j;
            ans[i][j] = NIL;
        }
    }
    while(q--) {
        int ty, r, c, x;
        cin >> ty;
        if(ty == 1) {
            cin >> r;
            r--;
            rotate(mat[r], mat[r] + 1, mat[r] + m);
        }else if(ty == 2) {
            cin >> c;
            c--;
            vi ve(n);
            rep(i, 0, n) ve[i] = mat[i][c];
            rotate(ve.begin(), ve.begin() + 1, ve.end());
            rep(i, 0, n) mat[i][c] = ve[i];
        }else {
            cin >> r >> c >> x;
            r--; c--;
            ans[mat[r][c] / m][mat[r][c] % m] = x;
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            cout << (ans[i][j] == NIL ? 0 : ans[i][j]) << ' ';
        }
        cout << '\n';
    }
}