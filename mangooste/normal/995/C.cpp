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

const int A = 1e6;
const ll MAX = 1ll * A * A;

inline ll sqr(int x) {
    return 1ll * x * x;
}

struct point {
    int x, y, id;

    point() : x(0), y(0), id(-1) {}

    point(int x, int y) : x(x), y(y), id(-1) {}

    ll operator%(const point p) const {
        return 1ll * x * p.y - 1ll * y * p.x;
    }

    ll operator*(const point p) const {
        return 1ll * x * p.x + 1ll * y * p.y;
    }

    ll len2() const {
        return sqr(x) + sqr(y);
    }

    point operator+(const point p) const {
        return point(x + p.x, y + p.y);
    }

    point operator-(const point p) const {
        return point(x - p.x, y - p.y);
    }

    point operator*(const int k) const {
        return point(x * k, y * k);
    }

    friend istream& operator>>(istream &in, point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream &out, point p) {
        return out << '(' << p.x << ", " << p.y << ", " << p.id << ')';
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<point> points(n);
    for (auto &p : points)
        cin >> p;

    vec<vec<int>> elements(n);
    vec<int> answer(n);
    for (int i = 0; i < n; i++)
        elements[i] = {i};

    auto unite = [&](int a, int b) {
        points[a].x += points[b].x;
        points[a].y += points[b].y;

        for (auto i : elements[b])
            elements[a].push_back(i);

        elements[b].clear();
    };

    auto reverse = [&](int v) {
        for (auto i : elements[v]) {
            answer[i] ^= 1;
            points[i] = points[i] * -1;
        }
    };

    vec<int> st(n);
    iota(all(st), 0);
    while (len(st) > 2) {
        ar<int, 3> current{st.end()[-3], st.end()[-2], st.end()[-1]};
        st.pop_back();
        st.pop_back();
        st.pop_back();

        sort(all(current), [&](int a, int b) {
            return len(elements[a]) > len(elements[b]);
        });

        bool found = false;

        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if ((points[current[i]] + points[current[j]]).len2() <= MAX && !found) {
                    unite(current[i], current[j]);
                    found = true;
                }

        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if ((points[current[i]] - points[current[j]]).len2() <= MAX && !found) {
                    reverse(current[j]);
                    unite(current[i], current[j]);
                    found = true;
                }

        assert(found);

        sort(all(current), [&](int a, int b) {
            return len(elements[a]) > len(elements[b]);
        });

        for (int i = 0; i < 2; i++)
            st.push_back(current[i]);
    }

    if (len(st) > 1) {
        assert(len(st) == 2);

        int a = st[0];
        int b = st[1];

        if ((points[a] + points[b]).len2() > sqr(1.5 * A))
            reverse(b);
    }

    for (auto x : answer)
        cout << (x ? 1 : -1) << ' ';

    cout << '\n';
}