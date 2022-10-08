
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

const int N = 3e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    vector<vi> ve(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        ve[a[i]].push_back(i);
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int f = 0;
        rep(s, 0, 30) {
            int p = rand(l, r);
            int it = lower_bound(all(ve[a[p]]), r + 1) - ve[a[p]].begin();
            int it2 = lower_bound(all(ve[a[p]]), l) - ve[a[p]].begin();
            if(it - it2 > f) f = it - it2;
        }
        cout << max(1, 2 * f - (r - l + 1)) << '\n';
    }
}