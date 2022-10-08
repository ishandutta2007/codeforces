
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

// sum = r - l + 1
// pref[r] - pref[l-1] = r - l + 1
// (pref[r] - r) = (pref[l-1] - (l-1))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        string s;
        cin >> n >> s;
        vi a(n + 1);
        a[0] = 0;
        rep(i, 1, n + 1) {
            a[i] = (s[i - 1] - '0') + a[i - 1];
        }
        map<int, int> ma;
        ll ans = 0;
        rep(i, 0, n + 1) {
            ans += ma[a[i] - i];
            ma[a[i] - i]++;
        }
        cout << ans << '\n';
    }
}