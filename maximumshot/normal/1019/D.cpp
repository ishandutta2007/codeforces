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

const int N = 2005;

struct pt {
    int x = 0;
    int y = 0;
    int id = 0;

    pt() = default;

    pt(int _x, int _y): x(_x), y(_y), id(0)
    { }

    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }

    ll vector_mul(const pt &o) const {
        return 1ll * x * o.y - 1ll * o.x * y;
    }

    bool operator<(const pt &o) const {
        return this->vector_mul(o) > 0;
    }
} p[N];

bool cmp(const pt &p1, const pt &p2) {
    return p1.y < p2.y || p1.y == p2.y && p1.x < p2.x;
}

int n;
ll S;
int pos[N];

ll _area(const pt &p1, const pt &p2, const pt &p3) {
    return abs((p2 - p1).vector_mul(p3 - p1));
}

void print(const pt &p1, const pt &p2, const pt &p3) {
    puts("Yes");
    printf("%d %d\n", p1.x, p1.y);
    printf("%d %d\n", p2.x, p2.y);
    printf("%d %d\n", p3.x, p3.y);
    exit(0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %lld", &n, &S);

    S <<= 1;

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
        p[i].id = i;
    }

    vec< tuple< pt, int, int > > arr;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            pt v = p[i] - p[j];
            if(v.y > 0 || v.y == 0 && v.x > 0) {
                v.x *= -1;
                v.y *= -1;
            }
            arr.emplace_back(v, i, j);
        }
    }

    sort(ALL(arr));
    sort(p + 1, p + n + 1, cmp);

    for(int i = 1;i <= n;i++) {
        pos[p[i].id] = i;
    }

    for(auto iter : arr) {
        pt v;
        int i, j;
        tie(v, i, j) = iter;

        int pi = pos[i];
        int pj = pos[j];

        if(pi > pj) swap(pi, pj);

        // pi + 1 == pj

        int bl, br, bm;

        bl = 1;
        br = pi;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            ll val = _area(p[pi], p[pj], p[bm]);
            if(val > S) bl = bm;
            else br = bm;
        }

        for(int k = bl;k <= br;k++) {
            if(_area(p[pi], p[pj], p[k]) == S) {
                print(p[pi], p[pj], p[k]);
            }
        }

        bl = pj;
        br = n;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            ll val = _area(p[pi], p[pj], p[bm]);
            if(val > S) br = bm;
            else bl = bm;
        }

        for(int k = bl;k <= br;k++) {
            if(_area(p[pi], p[pj], p[k]) == S) {
                print(p[pi], p[pj], p[k]);
            }
        }

        swap(p[pi], p[pj]);
        swap(pos[i], pos[j]);
    }

    puts("No");

    return 0;
}