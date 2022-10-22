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
int now_itr;
vector<int> vertexs[1000000];
pair<int, int> ans[1000000];
int dfs(int now, int back) {
    for (auto next : vertexs[now]) {
        if (next == back) continue;
        dfs(next, now);
    }
    ans[now].second = now_itr;
    now_itr--;
    reverse(ALL(vertexs[now]));
    for (auto next : vertexs[now]) {
        if (next == back) continue;
        ans[next].first = now_itr;
        now_itr--;
    }
    return 0;
}
void solve(){
    int n;
    cin >> n;
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        vertexs[a].push_back(b);
        vertexs[b].pb(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (vertexs[i].size() <= 1) {
            now_itr = 2 * n;
            dfs(i, -1);
            ans[i].first = 1;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return;
}
int main() {
    init();
    solve();
}