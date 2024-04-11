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
void solve(){
    string s;
    cin >> s;
    map<char, int> already;
    pair<int, int> now;
    REP(i, s.length()) {
        if (already.find(s[i]) == already.end()) {
            already[s[i]] = i;
        }
        else {
            now = mp(already[s[i]], i);
            s.erase(s.begin() + i);
            break;
        }
    }
    if (now.second == now.first + 1) {
        cout << "Impossible" << endl;
        return;
    }
    string a, b;
    REP(i, 13) {
        a.push_back('a');
        b.push_back('a');
    }
    int lengths = now.second - now.first;
    REP(i, s.length()) {
        if (i < 13) {
            a[i] = s[i];
        }
        else {
            b[i-13] = s[i];
        }
    }
    reverse(ALL(b));
    for (int i = 0;i < 100; ++i) {
        int ok = 0;
        int te = i%26;
        if (te >= 13) {
            te = 26 - te;
        }
        int place = te / 13;
        for (int q = 0;; ++q) {
            if (q == now.second) {
                if (place == 0) {
                    if (b[te] == s[now.first]) {
                        ok = 1;
                    }
                    if (te - 1 >= 0) {
                        if (b[te - 1] == s[now.first]) {
                            ok = 1;
                        }
                    }
                }
                else {
                    if (a[te] == s[now.first]) {
                        ok = 1;
                    }
                    if (te + 1 < b.length()) {
                        if (a[te + 1] == s[now.first]) {
                            ok = 1;
                        }
                    }
                }
                break;
            }
            if (place == 0) {
                if (te == 12) {
                    place = 1;
                }
                else {
                    te++;
                }
            }
            else {
                if (te == 0) {
                    place = 0;
                }
                else {
                    te--;
                }
            }
        }
        if (ok == 1) {
            cout << a << endl;
            cout << b << endl;
            return;
        }
        b.push_back(a.back());
        a.pop_back();
        a = b[0] + a;
        b.erase(b.begin());
    }
    cout << "Impossible" << endl;
}
#undef int
int main() {
    init();
    solve();
}