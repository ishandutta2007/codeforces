
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

// minimum sum. Greedily make deleted nodes have highest a_v possible.
// min(s_child - s_parent)

const int N = 1e5 + 5;
int n, p[N];
ll s[N], a[N];
vi child[N];

void dfs(int x) {
    if(s[x] == -1) {
        a[x] = LLONG_MAX;
        for(int y : child[x]) {
            a[x] = min(a[x], s[y] - s[p[x]]);
        }
        if(a[x] == LLONG_MAX) a[x] = 0;
        s[x] = a[x] + s[p[x]];
    }else if(x != 1) {
        a[x] = s[x] - s[p[x]];
    }
    for(int y : child[x]) {
        dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 2, n + 1) {
        cin >> p[i];
        child[p[i]].push_back(i);
    }
    rep(i, 1, n + 1) cin >> s[i];
    a[1] = s[1];
    dfs(1);
    if(*min_element(a + 1, a + n + 1) < 0) {
        cout << "-1\n";
    }else {
        cout << accumulate(a + 1, a + n + 1, 0LL) << '\n';
    }
}