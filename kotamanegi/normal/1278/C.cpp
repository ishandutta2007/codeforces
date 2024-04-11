/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         kotamanegi    pass System Test!
*/
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

#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> inputs;
    REP(i, 2*n) {
        ll a;
        cin >> a;
        inputs.pb(a);
    }
    int syusi = 0;
    REP(q, inputs.size()) {
        if (inputs[q] == 1) {
            syusi++;
        }
        else {
            syusi--;
        }
    }
    map<int, int> finding_ans;
    int geko = 0;
    finding_ans[0] = 0;
    for (int q = n; q < 2 * n; ++q) {
        if (inputs[q] == 1) {
            geko--;
        }
        else {
            geko++;
        }
        if (finding_ans.find(geko) == finding_ans.end()) {
            finding_ans[geko] = q - n + 1;
        }
    }
    geko = 0;
    ll ans = 1e9;
    if (finding_ans.find(-syusi) != finding_ans.end()) {
        ans = min(ans, (ll)finding_ans[-syusi]);
    }
    for (int q = n - 1; q >= 0; --q) {
        if (inputs[q] == 1) {
            geko--;
        }
        else {
            geko++;
        }
        int next = syusi + geko;
        if (finding_ans.find(-next) != finding_ans.end()) {
            ans = min(ans, n - q + finding_ans[-next]);
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    init();
    int test_case;
    cin >> test_case;
    REP(i, test_case) {
        solve();
    }
}