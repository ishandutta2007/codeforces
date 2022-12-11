#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int IT = 100;
const long double LIM = 1e9 + 1e8;

long double a, b, c, d;
long double l[4], r[4];

pair<long double, long double> get_range(int a, int b) {
    pair<long double, long double> result;
    result.first = l[a] * l[b];
    result.second = l[a] * l[b];

    result.first = min(result.first, l[a] * r[b] );
    result.second = max(result.second, l[a] * r[b] );

    result.first = min(result.first, r[a] * r[b] );
    result.second = max(result.second, r[a] * r[b] );

    result.first = min(result.first, r[a] * l[b] );
    result.second = max(result.second, r[a] * l[b] );

    return result;
} 

bool check(long double x) {
    l[0] = a - x; r[0] = a + x;
    l[1] = b - x; r[1] = b + x;
    l[2] = c - x; r[2] = c + x;
    l[3] = d - x; r[3] = d + x;

    pair<long double, long double> a = get_range(0, 1);
    pair<long double, long double> b = get_range(2, 3);

    return max(a.first, b.first) < min(a.second, b.second);
}

void solve() {
    cin >> a >> c >> d >> b;

    long double left = 0.0, right = LIM;

    for (int it = 0; it < IT; it++) {
        long double middle = (left + right) / 2;
        if (check(middle) ) {
            right = middle;
        } else {
            left = middle;
        }
    }

    cout << fixed << setprecision(12) << left << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}