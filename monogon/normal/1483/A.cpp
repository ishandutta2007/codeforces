
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
    int n, m;
    cin >> n >> m;
    vi k(m);
    vector<vi> ve(m);
    vi cnt(n + 1, 0);
    rep(i, 0, m) {
        cin >> k[i];
        ve[i].assign(k[i], 0);
        rep(j, 0, k[i]) {
            cin >> ve[i][j];
        }
        cnt[ve[i][0]]++;
    }
    vi ans(m);
    int fr = max_element(all(cnt)) - cnt.begin();
    rep(i, 0, m) {
        if(ve[i][0] == fr && cnt[fr] > (m + 1) / 2 && k[i] > 1) {
            ans[i] = ve[i][1];
            cnt[ve[i][0]]--;
            cnt[ve[i][1]]++;
        }else {
            ans[i] = ve[i][0];
        }
    }

    if(cnt[fr] > (m + 1) / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}