#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct pt {
    int x, y;

    pt(): x(0), y(0)
    { }

    pt(int _x, int _y): x(_x), y(_y)
    { }

    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }

    ll vector_mul(const pt &o) const {
        return 1ll * x * o.y - 1ll * o.x * y;
    }

    ll scalar_mul(const pt &o) const {
        return 1ll * x * o.x + 1ll * y * o.y;
    }

    ll len_sqr() const {
        return 1ll * x * x + 1ll * y * y;
    }
};

vec< pt > convex_hull(vec< pt > a) {
    int n = (int)a.size();
    {
        int j = -1;
        for(int i = 0;i < n;i++) {
            if(j == -1 || (a[i].x < a[j].x || (a[i].x == a[j].x && a[i].y < a[j].y))) {
                j = i;
            }
        }
        swap(a[j], a[0]);
    }

    sort(a.begin() + 1, a.end(), [&](pt p1, pt p2){
        ll sc_ml = (p1 - a[0]).vector_mul(p2 - a[0]);
        if(sc_ml > 0) return true;
        else if(sc_ml < 0) return false;
        return (p1 - a[0]).len_sqr() < (p2 - a[0]).len_sqr();
    });

    vec< pt > st;

    st.push_back(a[0]);

    for(int i = 1;i < n;i++) {
        pt p = a[i];

        while((int)st.size() >= 2) {
            pt p1 = st[(int)st.size() - 2];
            pt p2 = st[(int)st.size() - 1];
            if((p - p2).vector_mul(p1 - p2) > 0) {
                break;
            }
            st.pop_back();
        }

        st.push_back(p);
    }

    return st;
}

vec< pll > calc_seq(const vec< pt > &a) {
    vec< pll > res(a.size());
    for(int i = 0;i < (int)a.size();i++) {
        pt p = a[i];
        pt nx = a[(i + 1) % (int)a.size()];
        pt pr = a[(i - 1 + (int)a.size()) % (int)a.size()];
        res[i] = make_pair(
            (nx - p).scalar_mul(p - pr),
            (nx - p).len_sqr()
        );
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    scanf("%d %d", &n, &m);

    vec< pt > a(n), b(m);

    for(pt &p : a) scanf("%d %d", &p.x, &p.y);
    for(pt &p : b) scanf("%d %d", &p.x, &p.y);

    a = convex_hull(a);
    b = convex_hull(b);

    if(a.size() != b.size()) {
        puts("NO");
        return 0;
    }

    if((int)a.size() == 2) {
        if((a[0] - a[1]).len_sqr() == (b[0] - b[1]).len_sqr()) {
            puts("YES");
        }else {
            puts("NO");
        }
        return 0;
    }

    vec< pll > fa = calc_seq(a), fb = calc_seq(b);
    vec< pll > s = fb;

    s.push_back({inf64, inf64});
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < (int)fa.size();j++)
            s.push_back(fa[j]);

    int sz = (int)s.size();
    n = (int)fb.size();

    vec< int > P(sz);

    for(int i = 1;i < sz;i++) {
        int j = P[i - 1];
        while(j > 0 && s[i] != s[j]) j = P[j - 1];
        if(s[i] == s[j]) j++;
        P[i] = j;
    }

    for(int i = n + n + 1;i < sz;i++) {
        if(P[i] == n) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}