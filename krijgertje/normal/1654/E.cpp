#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
#include <functional>
#include <unordered_map>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// https://codeforces.com/blog/entry/62393 by neal
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint32_t x) const {
        static const uint64_t FIXED_RANDOM = rnd();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<int, int, custom_hash> safemap;

const int MAXN = 100000;

int n;
int a[MAXN];



int solve() {
    int amn = a[0]; FOR(i, 1, n) amn = min(amn, a[i]);
    int amx = a[0]; FOR(i, 1, n) amx = max(amx, a[i]);
    int lim = sqrt(1.0 * (amx - amn + 1));
    //printf("lim=%d\n", lim);
    int ret = n;
    int lo = amn - (n - 1) * lim, hi = amx + (n - 1) * lim;
    //printf("lo=%d hi=%d\n", lo, hi);
    vector<int> cnt(hi - lo + 1, 0);
    FORE(slope, -lim, +lim) {
        REP(i, n) {
            int v = a[i] - i * slope - lo;
            ++cnt[v];
            ret = min(ret, n - cnt[v]);
        }
        REP(i, n) {
            int v = a[i] - i * slope - lo;
            --cnt[v];
        }
        /*safemap mp;
        REP(i, n) ++mp[a[i] - (ll)i * slope];
        for (const auto &z : mp) {
            //printf("slope %d, offset %lld: %d\n", slope, z.first, z.second);
            int cur = n - z.second;
            ret = min(ret, cur);
        }*/
    }
    REP(i, n) {
        safemap mp;
        FOR(j, i + 1, n) {
            if (a[i] + (ll)(j - i) * (lim + 1) > amx && a[i] - (ll)(j - i) * (lim + 1) < amn) break;
            int num = a[j] - a[i], den = j - i;
            if (num % den != 0) continue;
            int slope = num / den;
            if (abs(slope) <= lim) continue;
            ++mp[slope];
        }
        for (const auto &z : mp) {
            //printf("start %d, slope %lld: %d\n", i, z.first, z.second + 1);
            int cur = n - (z.second + 1);
            ret = min(ret, cur);
        }
    }
    return ret;
}

void run() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    printf("%d\n", solve());
}

void stress() {
    std::mt19937 rnd(21312);
    REP(rep, 10) {
        n = MAXN;
        REP(i, n) a[i] = rnd() % 100000 + 1;
        solve();
        printf(".");
    }
}

int main() {
	run();
    //stress();
	return 0;
}