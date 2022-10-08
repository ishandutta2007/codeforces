
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

void solve() {
    int n, c;
    cin >> n >> c;
    vi cnt(c + 1, 0);
    rep(i, 0, n) {
        int a;
        cin >> a;
        cnt[a] = 1;
    }
    rep(i, 1, c + 1) cnt[i] += cnt[i - 1];
    rep(z, 1, c + 1) {
        if(cnt[z] > cnt[z - 1]) continue;
        for (int y = 1; z * y <= c; y++) {
            if(cnt[y] == cnt[y - 1]) continue;
            int mn = z * y - 1;
            int mx = min(c, (z + 1) * y - 1);
            if (cnt[mx] != cnt[mn]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}