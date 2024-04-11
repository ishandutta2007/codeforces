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
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
}
//@formatter:on

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

void shift(vector<vector<int>> &matrix, int j) {
    int t = matrix[0][j];
    for (int i = 1; i < matrix.size(); ++i) {
        matrix[i - 1][j] = matrix[i][j];
    }
    matrix[matrix.size() - 1][j] = t;
}

struct Point {
    int i, j;

    Point(int x, int y) : i(x), j(y) {}
};

int count(vector<vector<int>> &matrix) {
    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        int m = 0;
        for (int j = 0; j < matrix[0].size(); ++j) {
            m = max(m, matrix[i][j]);
        }
        ans += m;
    }
    return ans;
}

int best(vector<vector<int>> &matrix, set<int> j) {
    if (j.empty()) { return count(matrix); }
    int k = *j.begin();
    j.erase(k);
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        shift(matrix, k);
        ans = max(ans, best(matrix, j));
    }
    return ans;
}

struct S {
    int v;
    Point p;

    S(int w, int i, int j) : v(w), p(i, j) {}
    S():p(0, 0){}

    const bool operator<(const S &s) const {
        return v < s.v;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    cin >> matrix;
    vector<S> numbers(0);
    numbers.reserve(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            numbers.emplace_back(matrix[i][j], i, j);
        }
    }
    decr_sort(numbers);
    set<int> s;
    for (int k = 0; k < 5 && k < numbers.size(); ++k) {
        s.insert(numbers[k].p.j);
    }
    cout << best(matrix, s) << "\n";
}