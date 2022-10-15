#include <iostream>
#include <vector>
#include <set>
#include <map>
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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) { os << t << (space(t) ? " " : ""); } os << "\n"; return os; }
    ll gcd(ll a, ll b) { while (b) { ll mod = a % b; a = b; b = mod; } return a; }
    template<typename T>void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }
    template<typename T>void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
    vector<ll> prefix_sum(const vector<int> &v) { vector<ll> res(v.size()); res[0] = v[0]; for (int i = 0; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
}
//@formatter:on

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

struct Vertex {
    vector<Vertex *> children;
    int x;

    const bool operator<(const Vertex &v) const {
        return x < v.x;
    }
};

struct Cmp{
    const bool operator()(const Vertex *v1, const Vertex *v2) const {
        return v1->x < v2->x;
    }
};

struct Triangle {
    int a, b, c;

    Triangle(int a1 = 0, int b1 = 0, int c1 = 0) : a(a1), b(b1), c(c1) {}
};

Triangle t(vector<Vertex> &tree) {
    Vertex v = tree[0];
    if (v.children.size() < 2) return Triangle(-1, -1, -1);
    Vertex *w = v.children[0];
    for (Vertex *u:v.children) {
        if (binary_search(u->children.begin(), u->children.end(), w, Cmp()) != false) {
            return Triangle(v.x, u->x, w->x);
        }
    }
    return Triangle(-1, -1, -1);
}

bool nothing(vector<Vertex> v){
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            if (i == j)continue;
            if (binary_search(v[i].children.begin(), v[i].children.end(), &v[j], Cmp()))return false;
        }
    }
    return true;
}

bool everything(vector<Vertex> v1, vector<Vertex> v2){
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2.size(); ++j) {
            if (!binary_search(v1[i].children.begin(), v1[i].children.end(), &v2[j], Cmp()))return false;
        }
    }
    return true;
}

bool check(vector<vector<Vertex>> v, int m){
    if ((ll)v[0].size() * (ll)v[1].size() + (ll)v[1].size() * (ll)v[2].size() + (ll)v[0].size() * (ll)v[2].size() != m) return false;
    if ((ll)v[0].size() * (ll)v[0].size() >= 300000ll)swap(v[0], v[0]);
    if ((ll)v[1].size() * (ll)v[1].size() >= 300000ll)swap(v[0], v[1]);
    if ((ll)v[2].size() * (ll)v[2].size() >= 300000ll)swap(v[0], v[2]);
    return nothing(v[1]) && nothing(v[2]) && everything(v[0], v[1]) && everything(v[0], v[2]) && everything(v[1], v[2]);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<Vertex> tree(n);
    for (int i = 0; i < n; ++i) {
        tree[i].x = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        tree[a].children.push_back(&tree[b]);
        tree[b].children.push_back(&tree[a]);
    }
    for (int i = 0; i < n; ++i) {
        stable_sort(tree[i].children.begin(), tree[i].children.end(), Cmp());
    }
    vector<vector<Vertex>> v(3, vector<Vertex>());
    Triangle tr = t(tree);
    v[0].push_back(tree[tr.a]);
    v[1].push_back(tree[tr.b]);
    v[2].push_back(tree[tr.c]);
    for (int i = 0; i < n; ++i) {
        if (i == tr.a || i == tr.b || i == tr.c)continue;
        if (binary_search(tree[tr.a].children.begin(), tree[tr.a].children.end(), &tree[i]) +
            binary_search(tree[tr.b].children.begin(), tree[tr.b].children.end(), &tree[i]) +
            binary_search(tree[tr.c].children.begin(), tree[tr.c].children.end(), &tree[i]) == 2) {
            if (!binary_search(tree[tr.a].children.begin(), tree[tr.a].children.end(), &tree[i])) v[0].push_back(tree[i]);
            if (!binary_search(tree[tr.b].children.begin(), tree[tr.b].children.end(), &tree[i])) v[1].push_back(tree[i]);
            if (!binary_search(tree[tr.c].children.begin(), tree[tr.c].children.end(), &tree[i])) v[2].push_back(tree[i]);
        } else{
            cout << -1 << endl;
            return;
        }

    }
    if (!check(v, m)){
        cout << -1 << endl;
        return;
    } else{
        vector<int> ans(n);
        for (int i = 0; i < v[0].size(); ++i) {
            ans[v[0][i].x] = 1;
        }
        for (int i = 0; i < v[1].size(); ++i) {
            ans[v[1][i].x] = 2;
        }
        for (int i = 0; i < v[2].size(); ++i) {
            ans[v[2][i].x] = 3;
        }
        cout << ans;
    }
}