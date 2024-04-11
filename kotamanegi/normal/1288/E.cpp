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
#include <unordered_set>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>

using namespace std;
typedef string::const_iterator State;
const long double Ma_PI = 3.1415926535897932384626433832795028841971L;
#define eps 1e-15L
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*4
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
typedef struct BigInt {
    string s = "0";
    BigInt operator +(BigInt obj) {
        string c;
        while (max(obj.s.length(), this->s.length()) + 1 > c.length()) {
            c.pb('0');
        }
        for (int q = 0; q < obj.s.length(); ++q) {
            c[c.length() - 1 - q] = obj.s[obj.s.length() - q - 1];
        }
        for (int q = 0; q < this->s.length(); ++q) {
            c[c.length() - 1 - q] += this->s[this->s.length() - 1 - q] - '0';
            if (c[c.length() - 1 - q] > '9') {
                c[c.length() - 2 - q]++;
                c[c.length() - 1 - q] -= 10;
            }
        }
        if (c.front() == '0') {
            c.erase(c.begin());
        }
        return BigInt{ c };
    }
    BigInt operator *(BigInt obj) {
        BigInt ans;
        for (int i = this->s.length() - 1; i >= 0; --i) {
            REP(q, this -> s[i] - '0') {
                ans = ans + obj;
            }
            obj.s.pb('0');
        }
        return ans;
    }
}BigInt;

#define int ll

int minimum[400000];
int maximum[400000];

int places[400000];
int seg_tree[seg_size * 4];
int lazy_segtree[seg_size * 4];

int seg_find(int now, int n_l, int n_r, int w_l, int w_r, int setting) {
    if (w_l <= n_l && n_r <= w_r) {
        lazy_segtree[now] += setting;
    }
    seg_tree[now] += lazy_segtree[now];
    lazy_segtree[now * 2] += lazy_segtree[now];
    lazy_segtree[now * 2 + 1] += lazy_segtree[now];
    lazy_segtree[now] = 0;
    if (w_l <= n_l && n_r <= w_r) {
        return seg_tree[now];
    }
    if (w_r <= n_l || n_r <= w_l) {
        return 0;
    }
    return max(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r,setting), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r,setting));
}

void solve() {
    int n, m;
    cin >> n >> m;
    REP(i, n) {
        minimum[i + 1] = i + 1;
        maximum[i + 1] = i + 1;
    }
    int now_place = 0;
    for (int i = n; i >= 1; --i) {
        seg_tree[seg_size + (n - i)] = i;
        places[i] = now_place;
        now_place++;
    }
    REP(i, m) {
        int a;
        cin >> a;
        minimum[a] = 1;
        maximum[a] = max(maximum[a], seg_find(1, 0, seg_size, places[a], places[a] + 1, 0));
        seg_find(1, 0, seg_size, places[a], now_place, 1);
        places[a] = now_place;
        seg_tree[now_place+ seg_size] = 1;
        now_place++;
    }
    for (int a = 1; a <= n; ++a) {
        maximum[a] = max(maximum[a], seg_find(1, 0, seg_size, places[a], places[a] + 1, 0));
    }
    REP(i, n) {
        cout << minimum[i+1] << " " << maximum[i+1] << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}