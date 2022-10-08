
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

const int N = 2e5 + 5;
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
            ans = min(ans, n - (int) ((lower_bound(all(ve), make_pair(ve[i].first + 1, INT_MAX)) -
                    lower_bound(all(ve), make_pair(ve[i].first + 1, ve[i].second))) +
                    ((ve.begin() + i + 1) - lower_bound(all(ve), make_pair(ve[i].first, -1)))));
            if(i > 0 && ve[i].first == ve[i - 1].first) continue;
            while(j < n && (j <= i || ve[j].second > ve[j - 1].second)) j++;
            int val = 0;
            if(i > 0) {
                val += lower_bound(all(ve), make_pair(ve[i - 1].first, ve[i].second)) -
                       lower_bound(all(ve), make_pair(ve[i - 1].first, -1));
            }
            if(j < n) {
                val += lower_bound(all(ve), make_pair(ve[j].first, INT_MAX)) -
                       lower_bound(all(ve), make_pair(ve[j].first, ve[j - 1].second));
            }
            ans = min(ans, n - j + i - val);
        }
        cout << ans << '\n';
    }
}