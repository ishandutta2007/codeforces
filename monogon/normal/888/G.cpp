
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

const int N = 2e5 + 5;

struct node {
    int c[2] = {-1, -1}, dp = 1, val = 0;
};

int n, a[N];
vector<node> ve;
ll ans = 0;

int dfs(int x, int y) {
    if(ve[x].c[0] == -1 && ve[x].c[1] == -1) return ve[x].val ^ ve[y].val;
    int res = INT_MAX;
    if(ve[x].c[0] != -1) {
        res = min(res, dfs(ve[x].c[0], ve[y].c[0] == -1 ? ve[y].c[1] : ve[y].c[0]));
    }
    if(ve[x].c[1] != -1) {
        res = min(res, dfs(ve[x].c[1], ve[y].c[1] == -1 ? ve[y].c[0] : ve[y].c[1]));
    }
    return res;
}

void solve(int r) {
    if(r == -1) return;
    int L = ve[r].c[0], R = ve[r].c[1];
    solve(L);
    solve(R);
    if(L != -1 || R != -1) {
        ve[r].dp = (L == -1 ? 0 : ve[L].dp) + (R == -1 ? 0 : ve[R].dp);
    }
    if(L != -1 && R != -1) {
        if(ve[L].dp < ve[R].dp) {
            ans += dfs(L, R);
        }else {
            ans += dfs(R, L);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ve.emplace_back();
    rep(i, 0, n) {
        cin >> a[i];
        int r = 0;
        for(int l = 29; l >= 0; l--) {
            int b = ((a[i] >> l) & 1);
            if(ve[r].c[b] == -1) {
                ve[r].c[b] = sz(ve);
                ve.emplace_back();
            }
            r = ve[r].c[b];
        }
        ve[r].val = a[i];
    }
    solve(0);
    cout << ans << '\n';
}