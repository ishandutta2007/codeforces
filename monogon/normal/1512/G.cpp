
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

const int N = 1e7 + 5;
ll d[N], ans[N];

void solve() {
    int c;
    cin >> c;
    cout << ans[c] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 1, N) ans[i] = -1;
    rep(i, 1, N) {
        for(int j = i; j < N; j += i) {
            d[j] += i;
        }
        if(d[i] < N && ans[d[i]] == -1) ans[d[i]] = i;
    }

    int te;
    cin >> te;
    while(te--) solve();
}