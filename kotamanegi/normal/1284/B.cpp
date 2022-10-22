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
int minnest[2000000];
int maxest[2000000];
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> bo;
    REP(i, n) {
        int a;
        cin >> a;
        int now_max = 0;
        cin >> now_max;
        int now_min = now_max;
        int winner = 0;
        REP(q, a-1) {
            int b;
            cin >> b;
            if (b > now_min) {
                winner = 1;
            }
            now_min = b;
        }
        if (winner == 1) {
            ans++;
        }
        else {
            bo.pb(now_min);
            maxest[now_max]++;
        }
    }
    ans = ans * ans + 2LL * (n - ans) * ans;
    for (int i = 1000000; i >= 0; --i) {
        maxest[i] += maxest[i + 1];
    }
    sort(ALL(bo));
    REP(i, bo.size()) {
        ans += maxest[bo[i] + 1];
    }
    cout << ans << endl;
}
#undef int
int main() {
    init();
    solve();
}