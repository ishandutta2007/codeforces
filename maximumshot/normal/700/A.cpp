#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

double l, v1, v2;
int n, k;

bool check(double t) {
    double xmax = (t * v1 * v2 - l * v1) / (v2 - v1);
    double xmin = l - xmax;
    double tmin = xmin / v2;
    double x0;

    x0 = v1 * tmin;
    x0 += v1 * (xmin - x0) / (v1 + v2);

    double d = xmin - x0;
    double x = 0.0;

    for(int cnt = (n + k - 1) / k;cnt > 0;cnt--) {
        x += xmin;
        if(x > l) return false;
        x -= d;
    }

    return true;
}

bool solve() {

    cin >> n >> l >> v1 >> v2 >> k;

    double L, R, mid;

    L = l / v2;
    R = l / v1;

    for(int iter = 0;iter < 228;iter++) {
        mid = (L + R) / 2.0;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout.precision(10);
    cout << fixed << (L + R) / 2.0 << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}