
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
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
    }
    if(m % 2 == 1) {
        cout << "YES\n";
        rep(i, 0, m + 1) {
            cout << (i % 2 + 1) << ' ';
        }
        cout << '\n';
        return;
    }
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if(s[i][j] == s[j][i]) {
                cout << "YES\n";
                rep(k, 0, m + 1) {
                    cout << (k % 2 ? i+1 : j+1) << ' ';
                }
                cout << "\n";
                return;
            }
        }
    }
    if(n == 2) {
        cout << "NO\n";
        return;
    }
    for(char c : "ab") {
        rep(i, 0, n) {
            int j = 0, k = 0;
            while(j < n && (i == j || s[i][j] != c)) j++;
            while(k < n && (i == k || s[k][i] != c)) k++;
            if(j == n || k == n) continue;
            vector<int> ans, ans2;
            ans.push_back(i);
            rep(l, 0, m / 2) {
                ans.push_back(l % 2 == 0 ? j : i);
            }
            rep(l, 0, m / 2) {
                ans2.push_back(l % 2 == 0 ? k : i);
            }
            reverse(all(ans2));
            ans2.insert(ans2.end(), all(ans));
            ans.swap(ans2);

            cout << "YES\n";
            for(int x : ans) cout << x + 1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}