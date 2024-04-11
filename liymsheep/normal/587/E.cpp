#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MOD = 1000000007;

const int N = 200007;

struct Base {
    vector<int> b;
    int oz, ez;

    Base() {
        b.reserve(20);
        oz = ez = -1;
    }

    Base(const Base& o) {
        this->b = o.b;
        this->oz = o.oz;
        this->ez = o.ez;
    }

    void pre_xor(int x) {
        TR(it, b) *it ^= x;
        if (oz != -1) oz ^= x;
        if (ez != -1) ez ^= x;
    }
};

int carry[N * 8];
Base bases[N * 8];

int vals[N];

int highest_bit[(1 << 20) + 10];

int get_highest_bit(int x) {
    if (x < (1 << 20)) {
        return highest_bit[x];
    }
    return 20 + highest_bit[x >> 20];
}

int res[1000];

Base do_merge(const Base& a, const Base& b) {
    Base ret;
    int par = 0;
    int nRes = 0;

    TR(it, a.b) {
        int v = *it;
        int p = 1;
        REP(i, nRes) {
            int bit = get_highest_bit(res[i]);
            if ((v >> bit) & 1) {
                v ^= res[i];
                p ^= (par >> i) & 1;
            }
        }

        if (v) {
            par ^= (p << nRes);
            res[nRes++] = v;
            ret.b.PB(*it);
        } else {
            if (p == 0) {
                ret.ez = *it;
            } else {
                ret.oz = *it;
            }
        }
    }

    TR(it, b.b) {
        int v = *it;
        int p = 1;
        REP(i, nRes) {
            int bit = get_highest_bit(res[i]);
            if ((v >> bit) & 1) {
                v ^= res[i];
                p ^= (par >> i) & 1;
            }
        }

        if (v) {
            par ^= (p << nRes);
            res[nRes++] = v;
            ret.b.PB(*it);
        } else {
            if (p == 0) {
                ret.ez = *it;
            } else {
                ret.oz = *it;
            }
        }
    }

    VI vv;
    vv.reserve(4);
    if (a.oz != -1) {
        vv.PB(a.oz);
    }
    if (b.oz != -1) {
        vv.PB(b.oz);
    }
    if (a.ez != -1) {
        vv.PB(a.ez);
    }
    if (b.ez != -1) {
        vv.PB(b.ez);
    }

    TR(it, vv) {
        int v = *it;
        int p = 1;
        REP(i, nRes) {
            int bit = get_highest_bit(res[i]);
            if ((v >> bit) & 1) {
                v ^= res[i];
                p ^= (par >> i) & 1;
            }
        }

        if (v) {
            par ^= (p << nRes);
            res[nRes++] = v;
            ret.b.PB(*it);
        } else {
            if (p == 0) {
                ret.ez = *it;
            } else {
                ret.oz = *it;
            }
        }
    }

    return ret;
}

void do_xor(Base& v, int x) {
    v.pre_xor(x);
    v = do_merge(v, Base());
}

void build(int left, int right, int x) {
    if (left == right) {
        int v = vals[left];
        if (v) {
            bases[x].b.PB(v);
        } else {
            bases[x].oz = v;
        }
        return;
    }
    int mid = (left + right) >> 1;
    build(left, mid, x * 2);
    build(mid + 1, right, x * 2 + 1);
    bases[x] = do_merge(bases[x * 2], bases[x * 2 + 1]);
}

void down(int left, int right, int x) {
    int mid = (left + right) >> 1;
    if (carry[x]) {
        do_xor(bases[x * 2], carry[x]);
        carry[x * 2] ^= carry[x];

        do_xor(bases[x * 2 + 1], carry[x]);
        carry[x * 2 + 1] ^= carry[x];

        carry[x] = 0;
    }
}

void add(int left, int right, int l, int r, int x, int v) {
    if (l <= left && r >= right) {
        carry[x] ^= v;
        do_xor(bases[x], v);
        return;
    }

    down(left, right, x);

    int mid = (left + right) >> 1;
    if (l <= mid) {
        add(left, mid, l, r, x * 2, v);
    }
    if (r > mid) {
        add(mid + 1, right, l, r, x * 2 + 1, v);
    }

    bases[x] = do_merge(bases[x * 2], bases[x * 2 + 1]);
}

Base query(int left, int right, int l, int r, int x) {
    if (l <= left && r >= right) {
        return bases[x];
    }

    down(left, right, x);
    Base res;
    int mid = (left + right) >> 1;
    if (l <= mid) {
        res = query(left, mid, l, r, x * 2);
    }
    if (r > mid) {
        res = do_merge(res, query(mid + 1, right, l, r, x * 2 + 1));
    }
    return res;
}

int main() {
    REP(i, (1 << 20)) {
        highest_bit[0] = -1;
        for (int j = 19; j >= 0; --j) {
            if ((i >> j) & 1) {
                highest_bit[i] = j;
                break;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    REP(i, n) {
        scanf("%d", &vals[i]);
    }
    build(0, n - 1, 1);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            --l; --r;
            if (k) add(0, n - 1, l, r, 1, k);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            --l; --r;
            // TR(it, query(0, n - 1, l, r, 1).b) {
            //  cout << "*it = " << *it << endl;
            // }
            LL ans = query(0, n - 1, l, r, 1).b.size();
            ans = 1LL << ans;
            cout << ans << endl;
        }
    }
    return 0;
}