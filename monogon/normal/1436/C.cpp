
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

const int N = 1005, M = 1e9 + 7;
ll choose[N][N], fact[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, pos;
    cin >> n >> x >> pos;
    int l = 0, r = n;
    set<int> gx, lex;
    while(l < r) {
        int m = (l + r) / 2;
        if(m <= pos) {
            lex.insert(m);
            l = m + 1;
        }else {
            gx.insert(m);
            r = m;
        }
    }
    assert(l - 1 == pos);
    lex.erase(pos);
    int A = sz(lex);
    int B = sz(gx);
    rep(i, 0, N) rep(j, 0, N) {
        if(j == 0) {
            choose[i][j] = 1;
        }else if(i < j) {
            choose[i][j] = 0;
        }else {
            choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % M;
        }
    }
    fact[0] = 1;
    rep(i, 1, N) {
        fact[i] = (i * fact[i - 1]) % M;
    }
    // cout << x -  1 << ' ' << A << ' ' << n - x << ' ' << B << ' ' << n - A - B - 1 << endl;
    ll ans = (((choose[x - 1][A] * choose[n - x][B]) % M) * fact[n - A - B - 1]) % M;
    ans = (ans * fact[A]) % M;
    ans = (ans * fact[B]) % M;
    cout << ans << '\n';
}