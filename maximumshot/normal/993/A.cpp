#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

struct pt {
    int x, y;
    pt operator - (pt const & o) const {
        return {x - o.x, y - o.y};
    }
    bool operator == (pt const & o) const {
        return x == o.x && y == o.y;
    }
    int vector_mul(pt const & o) const {
        return x * o.y - o.x * y;
    }
};

bool inside(pt p, vec< pt > const &a) {
    int have0 = 0;
    int minus = 0;
    int plus = 0;
    for(int i = 0;i < (int)a.size();i++) {
        int j = i; if(++j == (int)a.size()) j = 0;
        pt v1 = {a[j].x - a[i].x, a[j].y - a[i].y};
        pt v2 = {p.x - a[i].x, p.y - a[i].y};
        int val = v1.x * v2.y - v2.x * v1.y;
        if(val < 0) minus = 1;
        if(val > 0) plus = 1;
        if(val == 0) have0 = 1;
    }
    if(have0) {
        if(plus || minus) return false;
        else return true;
    }else {
        if(plus && minus) return false;
        else  return true;
    }
}

bool intersect(pt a, pt b, pt c, pt d) {
    if(a == c || a == d || b == d) return true;
    pt v1, v2, v3;
    int val1, val2;

    v3 = b - a;
    v1 = d - a;
    v2 = c - a;

    val1 = v3.vector_mul(v1);
    val2 = v3.vector_mul(v2);

    if(val1 > 0 && val2 > 0 || val1 < 0 && val2 < 0) return false;

    swap(a, c);
    swap(b, d);

    v3 = b - a;
    v1 = d - a;
    v2 = c - a;

    val1 = v3.vector_mul(v1);
    val2 = v3.vector_mul(v2);

    if(val1 > 0 && val2 > 0 || val1 < 0 && val2 < 0) return false;

    return true;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    vec< pt > a(4), b(4);

    for(pt &p : a) cin >> p.x >> p.y;
    for(pt &p : b) cin >> p.x >> p.y;

    for(int it = 0;it < 2;it++, swap(a, b)) {
        for(pt p : a) {
            if(inside(p, b)) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    for(int i = 0;i < (int)a.size();i++) {
        for(int j = 0;j < (int)b.size();j++) {
            int i2 = i + 1;
            int j2 = j + 1;
            if(i2 == (int)a.size()) i2 = 0;
            if(j2 == (int)b.size()) j2 = 0;
            if(intersect(a[i], a[i2], b[j], b[j2])) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}