#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define VAR(i, x) __typeof(x) i = (x)
#define FORE(i, x) for (VAR(i, (x).begin()); i != (x).end(); ++i)
#define FOR(i,a,b) for (i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (i = (a); i >= (b); --i)
#define REP(i,x) for(i = 0; i < (x); ++i)
#define MP make_pair
#define PB push_back

typedef pair<int, int> PII;
typedef long long LL;

struct Tree {
    int n;
    vector<LL> t;

    Tree (int _n) :
        n(_n),
        t(_n + 1, 0LL) {}

    void ad(int x, LL v) {
        while (x >= 1) {
            t[x] += v;
            x -= x & -x;
        }
    }

    LL sm(int x) {
        LL res = 0;
        while (x <= n) {
            res += t[x];
            x += x & -x;
        }
        return res;
    }

    void ad_int(int l, int r, LL v) {
        if (l > r) {
            return;
        }
        ad(r, v);
        ad(l - 1, -v);
    }
};

const int N = 1000005;

int le[N], ri[N];

int n;
int t[N];

void find_le() {
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        while (!v.empty() && t[v.back()] > t[i]) {
            v.pop_back();
        }
        if (!v.empty()) {
            le[i] = v.back();
        } else {
            le[i] = 0;
        }
        v.PB(i);
    }
}

void find_ri() {
    vector<int> v;
    for (int i = n; i >= 1; --i) {
        while (!v.empty() && t[v.back()] >= t[i]) {
            v.pop_back();
        }
        if (!v.empty()) {
            ri[i] = v.back();
        } else {
            ri[i] = n + 1;
        }
        v.PB(i);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
    }
    find_le();
    find_ri();
    Tree sum1(n);
    Tree sumx(n);
    for (int i = 1; i <= n; ++i) {
        int l = i - le[i] - 1;
        int r = ri[i] - i - 1;
        int b1 = min(l, r) + 1;
        int b2 = max(l, r) + 1;
        int b3 = l + r + 1;
            assert(b1 >= 1);
        sumx.ad_int(1, b1, t[i]);
        sum1.ad_int(b1 + 1, b2, b1 * (LL) t[i]);
        sum1.ad_int(b2 + 1, b3, (b1 + b2) * (LL) t[i]);
        sumx.ad_int(b2 + 1, b3, -t[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int k;
        scanf("%d", &k);
        LL res = sumx.sm(k) * (LL) k + sum1.sm(k);
        printf("%.12lf\n", (double) (((long double) res) / (long double) (n - k + 1)));
    }
}