
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

// for each segment, store size of left subtree or -1 if impossible

const int N = 105;
int dp[N][N], lmax[N], rmin[N], rmax[N];
bool vis[N][N];
int n, c;

void solve(int L, int R) {
    if(vis[L][R] || R < L) return;
    vis[L][R] = true;
    // root is L
    dp[L][R] = -1;
    if(rmax[L] > R) return;
    rep(i, max(L, lmax[L]) + 1, min(R + 1, rmin[L]) + 1) {
        solve(L + 1, i - 1);
        solve(i, R);
        if(dp[L + 1][i - 1] != -1 && dp[i][R] != -1) {
            dp[L][R] = i;
            return;
        }
    }
}

void answer(int L, int R) {
    if(R < L) return;
    assert(dp[L][R] != -1);
    answer(L + 1, dp[L][R] - 1);
    cout << L << ' ';
    answer(dp[L][R], R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    rep(i, 1, n + 1) {
        lmax[i] = -1;
        rmin[i] = INT_MAX;
        rmax[i] = -1;
    }
    rep(i, 0, c) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if(b <= a) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if(s == "LEFT") {
            lmax[a] = max(lmax[a], b);
        }else {
            rmin[a] = min(rmin[a], b);
            rmax[a] = max(rmax[a], b);
        }
    }
    solve(1, n);
    if(dp[1][n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    answer(1, n);
    cout << '\n';
}