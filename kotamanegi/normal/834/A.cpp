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
void solve(){
    string c, d;
    cin >> c >> d;
    int a = 0;
    int b = 0;
    int n;
    cin >> n;
    string s[4] = { "v","<","^",">" };
    REP(i, 4) {
        if (c == s[i]) {
            a = i;
        }
    }
    REP(i, 4) {
        if (d == s[i]) {
            b = i;
        }
    }
    if (n % 2 == 0) {
        cout << "undefined" << endl;
    }
    else if ((a + n) % 4 == b) {
        cout << "cw" << endl;
    }
    else if ((a + n * 3LL) % 4 == b) {
        cout << "ccw" << endl;
    }
    else {
        cout << "undefined" << endl;
    }
}
#undef int
int main() {
    init();
    solve();
}