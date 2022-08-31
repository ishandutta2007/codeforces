#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
int n;
const int MX = 100000;
int a[1000][6];

int getsc(int a, int b) {
    if (a * 32 <= b)
        return 3000;
    if (a * 16 <= b)
        return 2500;
    if (a * 8 <= b)
        return 2000;
    if (a * 4 <= b)
        return 1500;
    if (a * 2 <= b)
        return 1000;
    return 500;
}
int cc[6];

int main() {
    cin >> n;
    int ntmp = n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
            if (a[i][j] != -1)
                ++cc[j];
        }
    for (int i = 0; i < MX; ++i) {
        int n = ntmp + i;
        int df = 0;
        for (int j = 0; j < 5; ++j) {
            if (a[0][j] == -1 || a[1][j] == -1) {
                if (a[1][j] != -1)
                    df -= getsc(cc[j], n) - a[1][j] * getsc(cc[j], n) / 250;
                if (a[0][j] != -1)
                    df += getsc(cc[j], n) - a[0][j] * getsc(cc[j], n) / 250;
            }
            else {
                int d = a[1][j] - a[0][j];
                if (d >= 0)
                    df += d * getsc(cc[j], n) / 250;
                else
                    df -= (-d) * getsc(cc[j] + i, n) / 250;
            }
        }
        if (df > 0) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}