#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct point {
    int x, y;

    point() {}

    point(int x, int y) : x(x), y(y) {}

    bool operator<(const point p) const {
        return pair<int, int>{x, y} < pair<int, int>{p.x, p.y};
    }

    bool operator==(const point p) const {
        return x == p.x && y == p.y;
    }

    bool operator!=(const point p) const {
        return x != p.x || y != p.y;
    }

    friend istream& operator>>(istream &in, point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream &out, point p) {
        return out << p.x << ' ' << p.y;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    ar<point, 3> points;
    for (auto &p : points)
        cin >> p;

    set<point> answer;

    auto insert_way = [&](point from, point to) {
        if (to.x < from.x)
            swap(to, from);

        while (from != to) {
            answer.insert(from);
            if (from.x != to.x) {
                from.x++;
                continue;
            }

            if (from.y > to.y)
                from.y--;
            else if (from.y < to.y)
                from.y++;
        }

        answer.insert(to);
    };

    auto output = [&]() {
        cout << len(answer) << '\n';
        for (auto p : answer)
            cout << p << '\n';

        cout << '\n';
    };

    point best;
    int best_dist = INT_MAX;

    for (int x = 0; x <= 1000; x++)
        for (int y = 0; y <= 1000; y++) {
            int cur_dist = 0;
            for (int i = 0; i < 3; i++) {
                cur_dist += abs(points[i].x - x);
                cur_dist += abs(points[i].y - y);
            }

            if (best_dist > cur_dist) {
                best_dist = cur_dist;
                best = point(x, y);
            }
        }

    for (int i = 0; i < 3; i++)
        insert_way(best, points[i]);

    output();
}