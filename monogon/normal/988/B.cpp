
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    sort(all(s), [&](string &a, string &b) { return a.length() < b.length(); });
    auto sub = [&](const string &a, const string &b) {
        int n = a.length(), m = b.length();
        rep(i, 0, m - n + 1) {
            bool ok = true;
            rep(j, 0, n) {
                if(a[j] != b[i + j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    };
    rep(i, 1, n) {
        if(!sub(s[i - 1], s[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    rep(i, 0, n) cout << s[i] << '\n';
}