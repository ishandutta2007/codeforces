
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

const int N = 1e5 + 5;
int n;
ll a[6], b[N];
vi conflict[2 * N];
int str[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 0, 6) {
        cin >> a[i];
    }
    sort(a, a + 6);
    cin >> n;
    multiset<tuple<ll, int, int>> ve;
    rep(i, 0, n) {
        cin >> b[i];
        ve.emplace(b[i] - a[5], i, 5);
    }
    ll ans = LLONG_MAX;
    while(true) {
        ans = min(ans, get<0>(*prev(ve.end())) - get<0>(*ve.begin()));
        ll val;
        int idx, jdx;
        tie(val, idx, jdx) = *ve.begin();
        if(jdx == 0) break;
        ve.erase(ve.begin());
        ve.emplace(b[idx] - a[jdx - 1], idx, jdx - 1);
    }
    cout << ans << '\n';
}