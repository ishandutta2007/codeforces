
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

#define LEFT_A 0
#define RIGHT_B 1
#define RIGHT_A 2

struct query {
    ll ti;
    int ty;
    ll le;
    bool operator<(const query &o) const {
        return pair{ti, ty} < pair{o.ti, o.ty};
    }
};

ll solve(vector<pair<ll, ll>> &A, vector<pair<ll, ll>> &B) {
    vector<query> Q;
    for(auto &pa : A) {
        Q.push_back({pa.first, LEFT_A, -1});
        Q.push_back({pa.second, RIGHT_A, pa.first});
    }
    for(auto &pa : B) {
        Q.push_back({pa.second, RIGHT_B, pa.first});
    }
    sort(all(Q));
    multiset<ll> left;
    ll ans = 0;
    for(auto &q : Q) {
        if(q.ty == LEFT_A) {
            left.insert(q.ti);
        }else if(q.ty == RIGHT_A) {
            left.erase(left.find(q.le));
        }else if(!left.empty()) {
            ans = max(ans, q.ti - max(q.le, *left.begin()));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> A, B;
    ll cost = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        cin >> b[i];
        cost += abs(a[i] - b[i]);
        if(a[i] < b[i]) A.push_back({a[i], b[i]});
        else B.push_back({b[i], a[i]});
    }
    cout << cost - 2 * max(solve(A, B), solve(B, A)) << '\n';
}