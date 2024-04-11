
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
    set<pii> pq;
    set<pii> se;
    rep(i, 1, n + 1) rep(j, 2, 5) {
        se.insert({i, j});
        pq.insert({i, j});
    }
    int x = 1, y = 0;
    vi A(n);
    rep(i, 0, n) {
        int a;
        cin >> a;
        A[i] = a;
        if(a != 0) {
            if(x > a || a > n) {
                cout << -1 << '\n';
                return 0;
            }
            while(x < a) {
                y++;
                if(y == 5) {
                    y = 0;
                    x++;
                }
                auto it = pq.lower_bound({x, y});
                if(it == pq.begin()) {
                    cout << -1 << '\n';
                    return 0;
                }
                se.erase(*prev(it));
                pq.erase(prev(it));
            }
            int t = 4 - y;
            auto it = pq.lower_bound({a + 1, 0});
            rep(i, 0, t) {
                if(it != pq.begin()) it = prev(it);
            }
            while(pq.begin() != it) pq.erase(pq.begin());
        }
        y++;
        if(y == 5) {
            y = 0;
            x++;
        }
    }
    for(auto &pa : pq) se.erase(pa);
    rep(i, 1, n + 1) rep(j, 0, 2) se.insert({i, j});
    vector<pii> ve(all(se));
    ve.resize(n);
    if(ve[n - 1].first != ve[n - 2].first) ve[n - 1] = {ve[n - 2].first, ve[n - 2].second + 1};
    if((A[n - 1] != 0 && A[n - 1] != ve[n - 1].first) || ve[n - 1].second == 5) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ve.back().first << '\n';
    for(auto &pa : ve) {
        cout << pa.first << ' ';
    }
    cout << '\n';
}