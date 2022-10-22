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
void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> inputs;
    REP(i, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        inputs.pb(mp(mp(a, b), mp(c, d)));
    }
    REP(te, 2) {
        priority_queue<pair<int, int>> highest_l;
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> lowest_r;
        sort(ALL(inputs));
        REP(i, n) {
            highest_l.push(mp(inputs[i].second.first,inputs[i].first.second));
            lowest_r.push(mp(inputs[i].second.second, inputs[i].first.second));
            while (highest_l.top().second < inputs[i].first.first) {
                highest_l.pop();
            }
            while (lowest_r.top().second < inputs[i].first.first) {
                lowest_r.pop();
            }
            if (inputs[i].second.second < highest_l.top().first) {
                cout << "NO" << endl;
                return;
            }
            if (inputs[i].second.first > lowest_r.top().first) {
                cout << "NO" << endl;
                return;
            }
        }
        REP(i, n) {
            swap(inputs[i].first, inputs[i].second);
        }
    }
    cout << "YES" << endl;
    return;
}
#undef int
int main() {
    init();
    solve();
}