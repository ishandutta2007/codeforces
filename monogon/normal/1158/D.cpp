
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    bool upper() const {
        return y > 0 || (y == 0 && x > 0);
    }
    ll dot(const pt &o) const {
        return x * o.x + o.y;
    }
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    bool operator<(const pt &o) const {
        if(upper() != o.upper()) return upper();
        return cross(o) > 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> p(n);
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
    }
    string s;
    cin >> s;
    s += 'L';
    vi ans;
    int idx = 0;
    rep(i, 0, n) {
        if(p[i].y < p[idx].y) idx = i;
    }
    ans.push_back(idx);
    vector<pair<pt, int>> ve;
    rep(i, 0, n) {
        if(i != idx) {
            ve.emplace_back(p[i] - p[idx], i);
        }
    }
    pt vec(1, 0);
    rep(k, 1, n) {
        sort(all(ve));
        auto it = lower_bound(all(ve), make_pair(vec, 0));
        if(it == ve.end()) it = ve.begin();
        if(s[k - 1] == 'L') {
            ans.push_back(it->second);
            ve.erase(it);
        }else {
            if(it == ve.begin()) it = prev(ve.end());
            else it = prev(it);
            ans.push_back(it->second);
            ve.erase(it);
        }
        vec = p[ans.back()] - p[ans[sz(ans) - 2]];
        pt vecrot(-vec.y, vec.x);
        for(auto &pa : ve) {
            pa = {p[pa.second] - p[ans[sz(ans) - 1]], pa.second};
        }
    }

    for(int x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}