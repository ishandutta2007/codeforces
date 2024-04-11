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

int union_tree[2000000];
int union_find(int now) {
    if (union_tree[now] == now) return now;
    return union_tree[now] = union_find(union_tree[now]);
}
void union_merge(int a, int b) {
    a = union_find(a);
    b = union_find(b);
    union_tree[a] = b;
}
void solve(){
    int n;
    cin >> n;
    REP(i, n) {
        union_tree[i] = i;
    }
    vector<pair<int, int>> seg;
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        seg.pb(mp(a, b));
    }
    sort(ALL(seg));
    set<pair<int,int>> now_here;
    for (int i = 0; i < seg.size(); ++i) {
        now_here.insert(mp(seg[i].second, i));
        while (now_here.empty() == false && seg[i].first > (*(now_here.begin())).first) {
            now_here.erase(now_here.begin());
        }
        for (auto a : now_here) {
            if (a.first >= seg[i].second) {
                break;
            }
            int q = a.second;
            if (union_find(i) == union_find(q)) {
                cout << "NO" << endl;
                return;
            }
            union_merge(i, q);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (union_find(0) != union_find(i)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}
int main() {
    init();
    solve();
}