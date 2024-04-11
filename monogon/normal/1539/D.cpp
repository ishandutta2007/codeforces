
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
    ll cost = 0;
    ll item = 0;
    deque<pair<ll, ll>> ve;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        ve.push_back({b, a});
    }
    sort(all(ve));
    while(!ve.empty()) {
        if(ve[0].first <= item) {
            item += ve[0].second;
            cost += ve[0].second;
            ve.pop_front();
        }else {
            ll amt = min(ve.back().second, ve[0].first - item);
            ve.back() = {ve.back().first, ve.back().second - amt};
            item += amt;
            cost += 2 * amt;
            if(ve.back().second == 0) ve.pop_back();
        }
    }
    cout << cost << '\n';
}