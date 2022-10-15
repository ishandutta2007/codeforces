#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
//@formatter:off
namespace {
    using namespace std;
    typedef long long ll;
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>bool space(vector<T>) { return false; }
    template<typename T>bool space(T) { return true; }
    bool space(char) { return false; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) { os << t << (space(t) ? "" : ""); } os << "\n"; return os; }
    ll gcd(ll a, ll b) { while (b) { ll mod = a % b; a = b; b = mod; } return a; }
    template<typename T>void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }
    template<typename T>void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }
    ll sum(const vector<ll> &v) { ll s = 0; for (ll value : v) s += value; return s; }
}
//@formatter:on

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

struct Vertex{
    vector<Vertex *> children;
    int comp = -1;
};

void dfs(Vertex *v, int c){
    if (v->comp == c) return;
    v->comp = c;
    for (Vertex *w : v->children){
        dfs(w, c);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Vertex> tree(n);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        tree[x].children.push_back(&tree[y]);
        tree[y].children.push_back(&tree[x]);
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (tree[i].comp == -1) dfs(&tree[i], c++);
    }
    cout << k + c - n << "\n";
}