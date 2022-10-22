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
#define int ll
int n, m;
int pow(int now, int tmp) {
    long long ans = 1;
    while (tmp != 0) {
        if (tmp % 2) {
            ans *= now;
            ans %= m;
        }
        tmp /= 2;
        now *= now;
        now %= m;
    }
    return ans;
}
int inv(int now) {
    return pow(now, m - 2LL);
}
void solve() {
    cin >> n >> m;
    long long ans = 1;
    for (long long i = 2; i <= n; ++i) {
        ans *= i;
        ans %= m;
    }
    long long geko = 0;
    long long tmp = 1;
    for (int i = 1; i <= n; ++i) {
        tmp *= i;
        tmp %= m;
        tmp *= inv(n - i + 1LL);
        tmp %= m;
        int bobo = tmp;
        bobo *= pow(n - i + 1LL, 2LL);
        bobo %= m;
        geko += bobo;
        geko %= m;
    }
    ans *= geko;
    ans %= m;
    cout << ans << endl;
    return;
}
#undef int
int main() {
    init();
    solve();
}