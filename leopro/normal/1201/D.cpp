#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

typedef long long ll;

namespace useful {
    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    bool space(vector<T>) { return false; }

    template<typename T>
    bool space(T) { return true; }

    bool space(char) { return false; }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) { os << t << (space(t) ? " " : ""); }
        os << "\n";
        return os;
    }

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }

    template<typename T>
    void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }
}
using namespace useful;

typedef long long ll;

struct Point {
    int x;
    int y;

    Point(int xx, int yy) : x(xx), y(yy) {}

    Point() = default;

    const bool operator<(const Point &p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

istream &operator>>(istream &is, Point &p) {
    is >> p.y >> p.x;
    return is;
}

int GoUp(const vector<int> &cols, int &x, int &y, Point where) {
    auto it1 = lower_bound(cols.begin(), cols.end(), x);
    if (it1 == cols.end()) --it1;
    auto it2 = it1 - 1;
    if (it2 < cols.begin()) it2 = cols.begin();
    return abs(where.y - y) + min(abs(x - *it1) + abs(*it1 - where.x),
                                  abs(x - *it2) + abs(*it2 - where.x));
}

int ToPoint(const vector<int> &cols, int x, int y, Point where) {
    if (y != where.y) return GoUp(cols, x, y, where);
    else return abs(where.x - x);
}

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<Point> t(k);
    cin >> t;
    vector<int> cols(q);
    cin >> cols;
    incr_sort(cols);
    incr_sort(t);

    vector<Point> T;
    T.reserve(2 * k);
    T.push_back(t[0]);
    if (t[1].y != t[0].y) T.push_back(t[0]);
    for (int i = 1; i < k - 1; ++i) {
        if (t[i - 1].y == t[i + 1].y) continue;
        if (t[i - 1].y != t[i].y && t[i].y != t[i + 1].y) T.push_back(t[i]);
        T.push_back(t[i]);
    }
    if (t[k - 2].y != t[k - 1].y) T.push_back(t[k - 1]);
    T.push_back(t[k - 1]);

    vector<ll> left(n + 1), right(n + 1);

    left[T[0].y] = ToPoint(cols, 1, 1, T[0]);
    right[T[1].y] = ToPoint(cols, 1, 1, T[1]);

    left[T[0].y] += abs(T[1].x - T[0].x);
    right[T[1].y] += abs(T[1].x - T[0].x);
    swap(left[T[0].y], right[T[1].y]);
    for (int i = 1; i < T.size() / 2; ++i) {
        left[T[2 * i].y] = min(left[T[2 * i - 2].y] + ToPoint(cols, T[2 * i - 2].x, T[2 * i - 2].y, T[2 * i]),
                               right[T[2 * i - 1].y] + ToPoint(cols, T[2 * i - 1].x, T[2 * i - 1].y, T[2 * i]));
        right[T[2 * i + 1].y] = min(left[T[2 * i - 2].y] + ToPoint(cols, T[2 * i - 2].x, T[2 * i - 2].y, T[2 * i + 1]),
                               right[T[2 * i - 1].y] + ToPoint(cols, T[2 * i - 1].x, T[2 * i - 1].y, T[2 * i + 1]));
        left[T[2 * i].y] += abs(T[2 * i + 1].x - T[2 * i].x);
        right[T[2 * i + 1].y] += abs(T[2 * i + 1].x - T[2 * i].x);
        swap(left[T[2 * i].y], right[T[2 * i + 1].y]);
    }

    cout << min(left[T[T.size() - 1].y], right[T[T.size() - 1].y]) << endl;
    return 0;
}