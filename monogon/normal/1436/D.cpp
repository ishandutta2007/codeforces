
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

const int N = 2e5 + 5;
int n;
vi child[N];
ll a[N];
ll ans;
int leaves[N];

void dfs(int x) {
    for(int y : child[x]) {
        dfs(y);
        leaves[x] += leaves[y];
        a[x] += a[y];
    }
    if(child[x].empty()) leaves[x]++;
    ans = max(ans, (a[x] + leaves[x] - 1) / leaves[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 2, n + 1) {
        int p;
        cin >> p;
        child[p].push_back(i);
    }
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    ans = 0;
    dfs(1);
    cout << ans << '\n';
}