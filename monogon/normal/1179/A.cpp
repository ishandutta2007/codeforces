
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
    int n, q;
    cin >> n >> q;
    int iter = 2 * n + 5;
    vector<pii> ans;
    deque<int> D;
    rep(i, 0, n) {
        int a;
        cin >> a;
        D.push_back(a);
    }
    rep(it, 0, iter) {
        ans.push_back({D[0], D[1]});
        int a = min(D[0], D[1]);
        int b = max(D[0], D[1]);
        D.pop_front();
        D.pop_front();
        D.push_front(b);
        D.push_back(a);
    }
    while(q--) {
        ll m;
        cin >> m;
        m--;
        if(m >= n + 3) {
            m = (n + 3) + ((m - n - 3) % (n - 1));
        }
        cout << ans[m].first << ' ' << ans[m].second << '\n';
    }
}