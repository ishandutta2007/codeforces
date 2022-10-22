#pragma comment (linker, "/STACK:256000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void solve() {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    int left = max(a, c - r);
    int right = min(b, c + r);
    cout << b - a - max(0,(right - left)) << endl;
}

int ok(vector<ll> a, ll start,ll k) {
    ll value = 0;
    for (int i = start; i >= 0; i -= k) {
        value += a[i];
        if (i - k < 0) {
            for (int q = i - 1; q >= 0; --q) {
                value += a[i];
            }
        }
    }
    return value;
}
void solve2() {
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> inputs;
    REP(i, n) {
        ll a;
        cin >> a;
        inputs.push_back(a);
    }
    sort(inputs.begin(), inputs.end());
    ll start_point = 0;
    long long bot = 0;
    for (int i = k - 1; i < n; i += k) {
        start_point += inputs[i];
        if (start_point <= p) {
            bot = i + 1;
        }
    }
    long long top = inputs.size()+1;
    while (top - bot > 1) {
        ll mid = (bot + top) / 2LL;
        if (ok(inputs, mid - 1, k) <= p) {
            bot = mid;
        }
        else {
            top = mid;
        }
    }
    cout << bot << endl;
}
int main() {
    init();
    int t;
    cin >> t;
    REP(i,t)
    solve2();
}