
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
ll a[N];
int b[N];
vi adj[N];
ll ans = 0;
vector<int> v1, v2;

void dfs(int x, int p) {
    for(int y : adj[x]) {
        if(y != p) {
            dfs(y, x);
            a[x] += max(a[y], 0LL);
        }
    }
    ans += a[x];
    if(a[x] >= 0) {
        v1.push_back(x);
    }else {
        v2.push_back(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) {
        cin >> b[i];
        if(b[i] != -1) adj[b[i]].push_back(i);
    }
    rep(i, 1, n + 1) {
        if(b[i] == -1) {
            dfs(i, -1);
        }
    }
    cout << ans << '\n';
    for(int x : v1) {
        cout << x << ' ';
    }
    reverse(all(v2));
    for(int x : v2) {
        cout << x << ' ';
    }
    cout << '\n';
}