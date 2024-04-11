#include <algorithm>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef set<int>::iterator setit;

struct segment {
    int l, r;

    segment(int _l, int _r) : l(_l), r(_r) {}

    int w() const
    {
        return this->r - this->l;
    }
};

bool operator<(const segment &a, const segment &b)
{
    if (a.w() != b.w()) {
        return a.w() > b.w();
    }
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

bool operator==(const segment &a, const segment &b)
{
    return a.l == b.l && a.r == b.r;
}

typedef set<segment>::iterator segit;

struct dim {
    set<int> values;
    set<segment> segments;
    ll best;

    dim() : values(), segments(), best(0) {}

    void init(int w)
    {
        values.insert(0);
        values.insert(w);
        segment s(0, w);
        segments.insert(s);
        best = w;
    }

    void update(int v)
    {
        pair<setit, bool> ret = values.insert(v);
        assert(ret.second);

        setit left = ret.first, right = ret.first;
        left--;
        right++;
        segment s(*left, *right);
        segments.erase(segments.find(s));

        segment s1(*left, v), s2(v, *right);

        assert(segments.insert(s1).second);
        assert(segments.insert(s2).second);

        best = segments.begin()->w();


//        cout << "debug" << endl;
//        for (setit it = values.begin(); it != values.end(); ++it) {
//            cout << *it << " ";
//        }
//        cout << endl;
//        for (segit it = segments.begin(); it != segments.end(); ++it) {
//            cout << "(" << it->l << ", " << it->r << ") ";
//        }
//        cout << endl;
    }
};

dim x, y;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false);
#endif // LOCAL

    int w, h, n, a;
    char ch;
    cin >> w >> h >> n;

    x.init(w);
    y.init(h);

    while (n--) {
        cin >> ch >> a;
        if (ch == 'H') {
            y.update(a);
        } else {
            x.update(a);
        }
//        cout << x.best << " x " << y.best << " = ";
        cout << (x.best * y.best) << endl;
    }

    return 0;
}