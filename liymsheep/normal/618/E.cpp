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

#include <unordered_set>
#include <unordered_map>

using namespace std;

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

const double PI = acos(-1.0);

using namespace std;

struct pt {
    double x,y;
    pt(double _x = 0,double _y = 0) { x = _x; y = _y;}
    pt operator + (const pt &p) const { return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const { return pt(x-p.x,y-p.y);}
    pt operator * (const double p) const { return pt(p*x,p*y);}

    pt unitfy() {
        pt a = *this;
        double len = sqrt(a.x * a.x + a.y * a.y);
        a.x /= len;
        a.y /= len;
        return a;
    }
};

struct mat {
    bool unit;
    double a[2][2];

    mat() {
        unit = true;
        a[0][0] = a[1][1] = 1.0;
        a[0][1] = a[1][0] = 0.0;
    }

    void pr() {
        cout << a[0][0] << ", " << a[0][1] << "\n" << a[1][0] << ", " << a[1][1] << endl;
    }

    void clear() {
        CLEAR(a);
    }

    mat operator * (const mat& b) {
        if (unit) {
            return b;
        }
        mat c;
        c.clear();
        REP(k, 2) REP(i, 2) REP(j, 2) {
            c.a[i][j] += a[i][k] * b.a[k][j];
        }
        c.unit = false;
        return c;
    }
};

const int N = 500007;

pt delta[N * 4];
mat cover[N * 4];

pt multiply(const pt& a, const mat& b) {
    pt c;
    c.x = a.x * b.a[0][0] + a.y * b.a[1][0];
    c.y = a.x * b.a[0][1] + a.y * b.a[1][1];
    return c;
}

void down(int x) {
    if (!cover[x].unit) {
        delta[x * 2] = multiply(delta[x * 2], cover[x]);
        cover[x * 2] = cover[x * 2] * cover[x];
        delta[x * 2 + 1] = multiply(delta[x * 2 + 1], cover[x]);
        cover[x * 2 + 1] = cover[x * 2 + 1] * cover[x];
        cover[x] = mat();
    }
    if (delta[x].x != 0 || delta[x].y != 0) {
        delta[x * 2] = delta[x * 2] + delta[x];
        delta[x * 2 + 1] = delta[x * 2 + 1] + delta[x];
        delta[x] = pt();
    }
}

void add(int left, int right, int l, int r, int x, pt d) {
    if (l <= left && r >= right) {
        delta[x] = delta[x] + d;
        return;
    }
    down(x);
    int mid = (left + right) >> 1;
    if (l <= mid) add(left, mid, l, r, x * 2, d);
    if (r > mid) add(mid + 1, right, l, r, x * 2 + 1, d);
}

void mul(int left, int right, int l, int r, int x, mat d) {
    if (l <= left && r >= right) {
        delta[x] = multiply(delta[x], d);
        cover[x] = cover[x] * d;
        return;
    }
    down(x);
    int mid = (left + right) >> 1;
    if (l <= mid) mul(left, mid, l, r, x * 2, d);
    if (r > mid) mul(mid + 1, right, l, r, x * 2 + 1, d);
}

pair<pt, mat> get(int left, int right, int at, int x) {
    if (left == right) {
        return MP(delta[x], cover[x]);
    }
    down(x);
    int mid = (left + right) >> 1;
    if (at <= mid) {
        return get(left, mid, at, x * 2);
    }
    return get(mid + 1, right, at, x * 2 + 1);
}

int n, q;

pt getPoint(int idx) {
    pair<pt, mat> pa = get(0, n, idx, 1);
    pt o(idx, 0);
    // pa.second.pr();
    return multiply(o, pa.second) + pa.first;
}

int main() {
    cin >> n >> q;
    while (q--) {
        int type, at, zz;
        scanf("%d%d%d", &type, &at, &zz);

        double z = zz;

        if (type == 1) {
            pt u = getPoint(at - 1);
            pt v = getPoint(at);

            pt d = v - u;
            d = d.unitfy() * zz;
            add(0, n, at, n, 1, d);
        } else {
            pt u = getPoint(at - 1);
            u = pt(0, 0) - u;
            add(0, n, at, n, 1, u);

            // {

            //     pt last = getPoint(n);
            //     printf("A1: %.12f %.12f\n", last.x, last.y);
            // }

            z = -z;

            mat m;
            m.unit = false;
            m.a[0][0] = cos(z / 180 * PI);
            m.a[1][0] = -sin(z / 180 * PI);
            m.a[0][1] = sin(z / 180 * PI);
            m.a[1][1] = cos(z / 180 * PI);

            mul(0, n, at, n, 1, m);

            // {

            //     pt last = getPoint(n);
            //     printf("A2: %.12f %.12f\n", last.x, last.y);
            // }

            u = pt(0, 0) - u;
            add(0, n, at, n, 1, u);

            // {

            //     pt last = getPoint(n);
            //     printf("A3: %.12f %.12f\n", last.x, last.y);
            // }
        }

        pt last = getPoint(n);
        printf("%.12f %.12f\n", last.x, last.y);
    }
    return 0;
}