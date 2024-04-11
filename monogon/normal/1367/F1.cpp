
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

const int N = 3005;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pii> ve;
        rep(i, 0, n) {
            cin >> a[i];
            ve.emplace_back(a[i], i);
        }
        sort(all(ve));
        int j = 0;
        int ans = n;
        rep(i, 0, n) {
            while(j < n && (j <= i || ve[j].second > ve[j - 1].second)) j++;
            ans = min(ans, n - j + i);
        }
        cout << ans << '\n';
    }
}