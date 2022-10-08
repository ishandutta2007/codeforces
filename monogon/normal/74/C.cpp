
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

const int N = 1e6 + 5;
int dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int offset(int i, int n, int m) {
    int x = (i + n) % (2 * (m - 1));
    if(x < 0) x += (2 * (m - 1));
    if(x >= m) x = 2 * (m - 1) - x;
    return x;
}

int solve(int n, int m) {
    fill(dsu, dsu + m, -1);
    rep(i, 0, m) {
        join(i, offset(i, 2 * (n - 1), m));
        join(i, offset(i, -2 * (n - 1), m));
    }
    int ans = 0;
    rep(i, 0, m) {
        ans += (dsu[i] < 0);
    }
    return ans;
}

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cout << solve(n, m) << '\n';
}