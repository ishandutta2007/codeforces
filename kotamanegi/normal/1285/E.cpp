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
const long double Ma_PI = 3.1415926535897932384626433832795028841971L;
#define eps 1e-7
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
int imos[2000000];
int cnt[2000000];
void solve() {
    map<int, int> zipper;
    int n;
    cin >> n;
    vector<pair<int, int>> inputs(n);
    REP(i, n) {
        cin >> inputs[i].first >> inputs[i].second;
        inputs[i].first *= 2LL;
        inputs[i].second *= 2LL;
        zipper[inputs[i].first] = 1;
        zipper[inputs[i].second] = 1;
        zipper[inputs[i].second + 1] = 1;
    }
    int now_itr = 0;
    for (auto x = zipper.begin(); x != zipper.end();++x) {
        x -> second = now_itr;
        now_itr++;
    }
    REP(i, now_itr + 10) {
        imos[i] = 0;
        cnt[i] = 0;
    }
    REP(i, n) {
        imos[zipper[inputs[i].first]]++;
        imos[zipper[inputs[i].second + 1]]--;
    }
    REP(i, now_itr + 10) {
        imos[i + 1] += imos[i];
    }
    for (int i = 0; i < now_itr + 10; ++i) {
        if (imos[i] == 1) {
            if (i == 0 || imos[i - 1] != 1) {
                cnt[i]++;
            }
        }
        cnt[i + 1] += cnt[i];
    }
    int back = 0;
    vector<int> right_move,left_move;
    for (int i = now_itr; i >= 0; --i) {
        if (imos[i] > 1) {
            if (back == 0) {
                right_move.pb(i);
                back = 1;
            }
        }
        else {
            back = 0;
        }
    }
    back = 0;
    REP(i, now_itr + 1) {
        if (imos[i] > 1) {
            if (back == 0) {
                left_move.pb(i);
                back = 1;
            }
        }
        else {
            back = 0;
        }
    }
    sort(ALL(left_move));
    sort(ALL(right_move));
    right_move.pb(1e9);
    left_move.pb(1e9);
    int base_ans = 0;
    back = 0;
    REP(i, now_itr + 1) {
        if (imos[i] > 0) {
            if (back == 0) {
                base_ans++;
                back = 1;
            }
        }
        else {
            back = 0;
        }
    }
    int ans = -1;
    for (int i = 0; i < inputs.size(); ++i) {
        int left = zipper[inputs[i].first];
        int right = zipper[inputs[i].second];
        int tmp_ans = 0;
        auto x = lower_bound(ALL(right_move), left);
        if (imos[left] == 1) {
            if (left >= 1 && imos[left - 1] >= 1) {
                tmp_ans++;
            }
            if (*x > right){
                if (imos[right + 1] == 0) {
                    tmp_ans--;
                }
                ans = max(ans, tmp_ans);
                continue;
            }
        }
        left = *x;
        x = lower_bound(ALL(left_move), right + 1);
        x--;
        if (imos[right] == 1) {
            if (imos[right + 1] >= 1) {
                tmp_ans++;
            }
        }
        right = *x;
        int bonus = cnt[right] - cnt[left];
        ans = max(ans, tmp_ans + bonus);
    }
    cout << base_ans + ans << endl;
}
#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(te,t)
    solve();
}