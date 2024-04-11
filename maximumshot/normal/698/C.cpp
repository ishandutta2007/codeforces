#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool is_so_easy(int n, int k, const vec< double > & p) {
    int cnt = 0;
    for(int i = 0;i < n;i++) {
        if(p[i] == 1) {
            cout.precision(10);
            cout << fixed;
            for(int j = 0;j < n;j++) cout << p[j] << ' ';
            cout << '\n';
            return true;
        }else if(p[i] > 0.0) cnt++;
    }
    if(cnt <= k) {
        cout.precision(10);
        cout << fixed;
        for(int i = 0;i < n;i++) {
            if(p[i] > 0) cout << 1.0 << ' ';
            else cout << p[i] << ' ';
        }
        cout << '\n';
        return true;
    }else return false;
}

bool solve() {

    int n, k;

    cin >> n >> k;

    vec< double > p(n);

    for(int i = 0;i < n;i++) cin >> p[i];

    if(is_so_easy(n, k, p)) return true;

    vec< double > dp(1 << n);

    dp[0] = 1.0;

    for(int mask = 0;mask < (1 << n);mask++) {
        if(__builtin_popcount(mask) >= k) continue;
        double good = 0.0;
        for(int add = 0;add < n;add++) {
            if((1 << add) & mask) {}
            else good += p[add];
        }
        if(good == 0) continue;
        for(int add = 0;add< n;add++) {
            if((1 << add) & mask) {}
            else {
                dp[mask | (1 << add)] += dp[mask] * (p[add] / good);
            }
        }
    }

    cout.precision(10);
    cout << fixed;

    for(int i = 0;i < n;i++) {
        double res = 0.0;
        for(int mask = 0;mask < (1 << n);mask++) {
            if(__builtin_popcount(mask) != k) continue;
            if((1 << i) & mask) res += dp[mask];
        }
        cout << res << ' ';
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}