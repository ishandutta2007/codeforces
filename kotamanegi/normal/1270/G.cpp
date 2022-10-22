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
pair<int, int> pluss[2000000], minuss[2000000];
int ans[2000000];
void solve() {
    int n;
    scanf("%lld", &n);
    int itr[2] = {};
    REP(i, n) {
        int a;
        scanf("%lld", &a);
        if (a < 0) {
            minuss[itr[1]] = mp(-a, i);
            itr[1]++;
        }
        else {
            pluss[itr[0]] = mp(a, i);
            itr[0]++;
        }
    }
    if (itr[0] != 0) {
        sort(pluss, pluss + itr[0]);
    }
    if (itr[1] != 0) {
        sort(minuss, minuss + itr[1]);
    }
    int now = 1;
    int ans_size = 0;
    while (now != 0) {
        int now_itr = 0;
        ans_size = 0;
        now = 0;
        for (int i = 0; i < itr[0]; ++i) {
            now += pluss[i].first;
            ans[ans_size] = pluss[i].second;
            ans_size++;
            while (now > 0 && now_itr < itr[1]) {
                now -= minuss[now_itr].first;
                ans[ans_size] = minuss[now_itr].second;
                ans_size++;
                now_itr++;
            }
            if (now == 0) break;
        }
        if (now != 0) {
            REP(i, 1000) {
                int a = xor128() % itr[0];
                if (a != itr[0] - 1) {
                    swap(pluss[a], pluss[a + 1]);
                }
            }
            REP(i, 1000) {
                int a = xor128() % itr[1];
                if (a != itr[1] - 1) {
                    swap(minuss[a], minuss[a + 1]);
                }
            }
        }
    }
    printf("%lld\n", ans_size);
    REP(i, ans_size) {
        printf("%lld ", ans[i] + 1);
    }
    printf("\n");
    return;
}
#undef int
int main() {
    //init();
    int t;
    scanf("%d", &t);
    REP(tea, t)
        solve();
}