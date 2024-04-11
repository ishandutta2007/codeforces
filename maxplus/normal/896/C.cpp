#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, seed, vmax;

int rnd() {
    int ret = seed;
    seed = (seed * 7ll + 13) % 1000000007;
    return ret;
}

struct segm {
    int l, r;
    int64_t x;
    segm(int l, int r = 0, int x = 0): l(l), r(r), x(x) {};
    bool operator <(const segm &oth) const {
        return l < oth.l;
    }
};

ostream& operator <<(ostream& out, const segm &t) {
    return out << t.l << ' ' << t.r << ' ' << t.x << '\n';
}

set<segm> s;

void Insert(segm t) {
    if (t.r > t.l)
        s.insert(t);
}

void split(int l) {
    segm lst = *prev(s.upper_bound(l)), rst = lst;
    s.erase(lst);
    lst.r = l;
    rst.l = l;
    Insert(lst);
    Insert(rst);
}

int64_t mpow(int64_t a, int64_t b, int64_t m) {
    int64_t res = 1;
    a %= m;
    for (int64_t p = a, d = 1; d <= b; d <<= 1, (p *= p) %= m)
        if (d & b)
            (res *= p) %= m;
    return res;
}

using pint = pair<int, int64_t>;

vector<pint> v;

int main()
{
    cin >> n >> m >> seed >> vmax;
    for (int i = 0; i < n; ++i) {
        Insert({i, i + 1, rnd() % vmax + 1});
    }
    for (int i = 0; i < m; ++i) {
        int op, l, r, x, y;
        {
            op = (rnd() % 4) + 1;
            l = (rnd() % n) + 1;
            r = (rnd() % n) + 1;

            if (l > r)
                 swap(l, r);

            if (op == 3)
                x = (rnd() % (r - l + 1)) + 1;
            else
                x = (rnd() % vmax) + 1;

            if (op == 4)
                y = (rnd() % vmax) + 1;
        }
        segm tmp(0);
        --l, r, --op;
        if (op == 0) {
            split(l);
            split(r);
            for (auto t = s.lower_bound(l); t != s.end() && *t < r; ++t)
                tmp = *t, (*(int64_t*)&t->x += x);
        }
        if (op == 1) {
            split(l);
            split(r);
            for (auto t = s.lower_bound(l); t != s.end() && *t < r; )
                t = s.erase(t);
            Insert({l, r, x});
        }
        if (op >= 2) {
            v.clear();
            for (auto t = prev(s.upper_bound(l)); t != s.end() && *t < r; ++t)
                tmp = *t, v.push_back({min(t->r, r) - max(t->l, l), t->x});
        }
        if (op == 2) {
            sort(v.begin(), v.end(), [](const pint &a, const pint &b) { return a.second < b.second; });
            --x;
            int i;
            for (i = 0; x >= 0; ++i)
                x -= v[i].first;
            cout << v[i - 1].second << '\n';
        }
        if (op == 3) {
            int64_t res = 0;
            for (auto i: v)
                (res += mpow(i.second, x, y) * i.first) %= y;
            cout << res << '\n';
        }
    }
    return 0;
}