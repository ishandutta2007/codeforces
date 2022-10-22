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
vector<int> vertexs[3000];
int color[3000];
vector<int> dfs(int now) {
    vector<int> now_ans;
    for (auto x : vertexs[now]) {
        vector<int> tmp = dfs(x);
        if (tmp.empty() == true) {
            now_ans.clear();
            return now_ans;
        }
        REP(i, tmp.size()) {
            now_ans.pb(tmp[i]);
        }
    }
    if (now_ans.size() < color[now]) {
        now_ans.clear();
        return now_ans;
    }
    now_ans.insert(now_ans.begin() + color[now], now);
    return now_ans;
}
void solve() {
    int n;
    cin >> n;
    int root;
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            root = i;
        }
        else {
            a--;
            vertexs[a].pb(i);
        }
        color[i] = b;
    }
    vector<int> ans = dfs(root);
    if (ans.empty() == true) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        int gogo[3000] = {};
        REP(i, n) {
            gogo[ans[i]] = i + 1;
        }
        REP(i, n) {
            cout << gogo[i] << " ";
        }
        cout << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}