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
    ll n, t, a, b;
    cin >> n >> t >> a >> b;
    vector<pair<ll,ll>> cost;
    REP(i, n) {
        ll c;
        cin >> c;
        cost.push_back(make_pair(-1, c));
    }
    REP(i, n) {
        cin >> cost[i].first;
    }
    sort(ALL(cost));
    long long cnt[2] = {};
    REP(i, n) {
        cnt[cost[i].second]++;
    }
    cost.push_back(make_pair(t + 1, -1));
    ll req_time = 0;
    ll ans = 0;
    REP(i, cost.size()) {
        ll rem_time = cost[i].first - 1;
        ll tmp_ans = i;
        rem_time -= req_time;
        if (rem_time >= 0) {
            ll can_solveeasy = rem_time / a;
            can_solveeasy = min(can_solveeasy, cnt[0]);
            tmp_ans += can_solveeasy;
            rem_time -= can_solveeasy * a;
            ll Hards = rem_time / b;
            Hards = min(Hards, cnt[1]);
            tmp_ans += Hards;
            ans = max(ans, tmp_ans);
        }
        if (cost[i].second == 0) {
            req_time += a;
            cnt[0]--;
        }
        else {
            req_time += b;
            cnt[1]--;
        }
    }
    cout << ans << endl;
}

int main() {
    init();
    int t;
    cin >> t;
    REP(i,t)
    solve();
}