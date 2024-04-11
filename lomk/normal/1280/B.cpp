/*input
1
4 4
AAAA
AAAA
AAAA

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
//const int N=;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

int n, m;
vector<vector<char> > mat;

bool checkCol(int col, int l, int r) {
    loop(i, l, r) if (mat[i][col] == 'P') return false;
    return true;
}

bool checkCol(int col) {
    loop(i, 0, n - 1) if (mat[i][col] == 'P') return false;
    return true;
}

bool check0() {
    loop(i, 0, m - 1) if (!checkCol(i)) return false;
    return true;
}

bool check1() {
    bool ok = true;
    if (checkCol(0) || checkCol(m - 1)) return true;
    return false;
    return ok;
}

bool check2() {
    loop(i, 1, m - 2) if (checkCol(i)) return true;
    if (checkCol(0, 0, 0) || checkCol(0, n - 1, n - 1)) return true;
    if (checkCol(m - 1, 0, 0) || checkCol(m - 1, n - 1, n - 1)) return true;
    return false;
}

bool check3() {
    loop(i, 1, m - 2)if (checkCol(i, 0, 0) || checkCol(i, n - 1, n - 1)) return true;
    return false;
}

int solve() {
    bool can = false;
    loop(i, 0, n - 1) {
        loop(j, 0, m - 1) {
            if (mat[i][j] == 'A') {
                can = true; break;
            }
        }
        if (can) break;
    }
    if (!can) return -1;
    if (check0()) return 0;
    if (check1()) return 1;
    if (check2()) return 2;
    if (check3()) return 3;
    return 4;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        mat.assign(n, vector<char>(m, '!'));
        loop(i, 1, n) {
            loop(j, 1, m) {
                cin >> mat[i - 1][j - 1];
            }
        }
        int ans = solve();
        if (ans != -1) {
            vector<vector<char> > mat2(m, vector<char>(n, '!'));
            loop(i, 0, n - 1) loop(j, 0, m - 1) mat2[j][i] = mat[i][j];
            swap(n, m); mat.swap(mat2);
            ans = min(ans, solve());
        }
        if (ans == -1) cout << "MORTAL" << endl;
        else cout << ans << endl;
    }

}