#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve();
        ++testNumber;
        //++timer;
    }

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {


}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

#define int li

//const int mod = 1000000007;

int mult(const vector<int>& a, int mask) {
    int res = a[2];
    for (int i = 0; i < 2; ++i) {
        if (mask & (1 << i)) {
            res += a[i];
        }
        else {
            res -= a[i];
        }
    }
    return res;
}

int get_floor(int x) {
    int res = x / 2 - 1;
    while (2 * res < x) {
        ++res;
    }
    return res;
}

int get_ceil(int x) {
    int res = x / 2 - 1;
    while (2 * (res + 1) <= x) {
        ++res;
    }
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    set<int> from_mask[4];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> points[i][j];
        }
        for (int mask = 0; mask < 4; ++mask) {
            from_mask[mask].insert(mult(points[i], mask));
        }
    }
    vector<vector<int>> extr(4, vector<int>(2));
    for (int mask = 0; mask < 4; ++mask) {
        extr[mask][0] = *(from_mask[mask].begin());
        extr[mask][1] = *(from_mask[mask].rbegin());
    }
    int L = -1, R = (li)3e18 + 10;
    int cur_x, cur_y, cur_z;
    while (L + 1 < R) {
        int d = (L + R) / 2;
        vector<int> min_val(4), max_val(4);
        bool f = true;
        for (int mask = 0; mask < 4; ++mask) {
            max_val[mask] = extr[mask][0] + d;
            min_val[mask] = extr[mask][1] - d;
            if (min_val[mask] > max_val[mask]) {
                f = false;
                break;
            }
        }
        if (!f) {
            L = d;
            continue;
        }

        int min_2x = max(min_val[1] - max_val[0], min_val[3] - max_val[2]);
        int max_2x = min(max_val[1] - min_val[0], max_val[3] - min_val[2]);

        int min_2y = max(min_val[2] - max_val[0], min_val[3] - max_val[1]);
        int max_2y = min(max_val[2] - min_val[0], max_val[3] - min_val[1]);

        int minx = get_floor(min_2x);
        int miny = get_floor(min_2y);

        int maxx = get_ceil(max_2x);
        int maxy = get_ceil(max_2y);

        if (minx > maxx || miny > maxy) {
            L = d;
            continue;
        }

        int min_2xy = min_val[3] - max_val[0];
        int max_2xy = max_val[3] - min_val[0];
        int min_sum = get_floor(min_2xy);
        int max_sum = get_ceil(max_2xy);

        min_2xy = min_val[1] - max_val[2];
        max_2xy = max_val[1] - min_val[2];
        int min_diff = get_floor(min_2xy);
        int max_diff = get_ceil(max_2xy);

        if (min_sum > max_sum || min_diff > max_diff) {
            L = d;
            continue;
        }

        maxx = min(maxx, get_ceil(max_sum + max_diff));
        minx = max(minx, get_floor(min_sum + min_diff));

        minx = max(minx, min_sum - maxy);
        maxx = min(maxx, max_sum - miny);
        maxx = min(maxx, max_diff + maxy);
        minx = max(minx, min_diff + miny);

        if (minx > maxx) {
            L = d;
        }
        else {
            R = d;
            cur_x = minx;
            cur_y = max(max(miny, min_sum - cur_x), cur_x - max_diff);
            cur_z = max(min_val[0] + cur_x + cur_y, min_val[1] - cur_x + cur_y);
            cur_z = max(cur_z, max(min_val[2] + cur_x - cur_y, min_val[3] - cur_x - cur_y));
        }
    }

    cout << cur_x << ' ' << cur_y << ' ' << cur_z << "\n";

}