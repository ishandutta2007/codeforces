#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

#define int li
//const int mod = 1000000007;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator + (const Point& ot) const {
        return Point(x + ot.x, y + ot.y);
    }
    Point operator - (const Point& ot) const {
        return Point(x - ot.x, y - ot.y);
    }
    int operator * (const Point& ot) const {
        return x * ot.y - y * ot.x;
    }
    int operator % (const Point& ot) const {
        return x * ot.x + y * ot.y;
    }
    void scan() {
        cin >> x >> y;
    }
    bool operator < (const Point& ot) const {
        return make_pair(x, y) < make_pair(ot.x, ot.y);
    }
    bool operator == (const Point& ot) const {
        return make_pair(x, y) == make_pair(ot.x, ot.y);
    }
};

bool check_sym(vector<Point> points, Point center) {
    vector<Point> init, sym;
    for (auto pt : points) {
        init.push_back(pt);
        Point sym_pt = center + center - pt;
        sym.push_back(sym_pt);
    }
    sort(all(init));
    sort(all(sym));
    return init == sym;
}

ld eps = 1e-9;

struct Hasher {
    int operator () (const Point& pt) const {
        return pt.x * 31 + pt.y;
    }
};

void solve(bool read) {
    int n;
    cin >> n;
    vector<Point> points(n);
    Point center(0, 0);
    for (int i = 0; i < n; ++i) {
        points[i].scan();
        points[i].x = points[i].x * 2;
        points[i].y = points[i].y * 2;
        center = center + points[i];
        points[i].x *= n;
        points[i].y *= n;
    }

    if (check_sym(points, center)) {
        cout << "-1\n";
        return;
    }

    unordered_map<Point, int, Hasher> cnt;
    vector<char> used(n, false);
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            auto cur = points[i] + points[j];
            cur.x /= 2;
            cur.y /= 2;
            cur = cur - center;
            if (cur == Point(0, 0)) {
                used[i] = true;
                used[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            auto cur = points[i] + points[j];
            cur.x /= 2;
            cur.y /= 2;
            cur = cur - center;
            if (cur.x < 0 || cur.x == 0 && cur.y < 0) {
                cur.x = -cur.x;
                cur.y = -cur.y;
            }
            int g = gcd(cur.x, abs(cur.y));
            cur.x /= g;
            cur.y /= g;
            ++cnt[cur];
        }
    }
    int rest = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++rest;
        }
    }
    vector<Point> check;
    for (auto item : cnt) {
        //cout << item.first.x << " " << item.first.y << " " << item.second << endl;
        if (item.second >= rest / 2) {
            check.push_back(item.first);
        }
    }

    assert(check.size() <= 2 * rest + 10);

    int ans = 0;
    vector<int> positive, negative;
    for (auto pt : check) {
        positive.clear();
        negative.clear();
        for (int i = 0; i < n; ++i) {
            Point cur = points[i] - center;
            int x = (cur * pt);
            if (x > 0) {
                positive.push_back(x);
            } else if (x < 0) {
                negative.push_back(-x);
            }
        }
        sort(all(positive));
        sort(all(negative));
        if (positive.size() != negative.size()) {
            continue;
        }
        bool flag = true;
        for (int i = 0; i < positive.size(); ++i) {
            if (positive[i] != negative[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            //cout << "good " << pt.x << " " << pt.y << endl;
            ++ans;
        }
    }

    cout << ans << "\n";

}