#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 100100;

int n, a[2], p[MAXN], ans[MAXN], deg[MAXN];
set<int> st;
map<int, int> ind;

void dfs(int cur, int b);

void go(int x) {
    if (st.count(x)) {
        if (deg[ind[x]] == 0) {
            cout << "NO\n";
            exit(0);
        } else {
            if (st.count(a[0]-x)) dfs(ind[x], 0);
            else if (st.count(a[1]-x)) dfs(ind[x], 1);
            else assert(0);
        }
    }
}

void dfs(int cur, int b) {
    if (ans[cur] != -1) return;
    ans[cur] = b;
    st.erase(p[cur]);
    ans[ind[a[b]-p[cur]]] = b;
    st.erase(a[b]-p[cur]);
    int x = a[!b]-p[cur], y = a[!b]-a[b]+p[cur];
    if (st.count(x)) deg[ind[x]]--;
    if (st.count(y)) deg[ind[y]]--;
    go(x);
    go(y);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> a[0] >> a[1];
    rep(i, n) {
        cin >> p[i];
        st.insert(p[i]);
        ind[p[i]] = i;
    }

    rep(i, n) {
        if (st.count(a[0]-p[i])) deg[ind[a[0]-p[i]]]++;
        if (st.count(a[1]-p[i])) deg[ind[a[1]-p[i]]]++;
    }

    memset(ans, -1, sizeof(ans));
    rep(i, n)
        if (ans[i] == -1 && (deg[i] < 2 || a[0] == a[1])) {
            if (deg[i] == 0) {
                cout << "NO\n";
                return 0;
            }
            if (st.count(a[0]-p[i])) dfs(i, 0);
            else dfs(i, 1);
        }

    cout << "YES\n";
    rep(i, n) cout << ans[i] << ' ';
    return 0;
}