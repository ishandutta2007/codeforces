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
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

    int n, k;

    scanf("%d %d", &n, &k);

    vec< int > c(n);
    for(int i = 0;i < n;i++) scanf("%d", &c[i]);

    vec< char > mark(n);

    ll tot = 0;
    ll ktot = 0;
    ll res = 0;

    for(int x, i = 0;i < k;i++) {
        scanf("%d", &x);
        mark[x - 1] = 1;
    }

    for(int i = 0;i < n;i++) {
        tot += c[i];
        if(mark[i]) ktot += c[i];
    }

    for(int i = 0;i < n;i++) {
        ll T = res;
        if(mark[i]) {
            res += 1ll * c[i] * (tot - c[i]);
        }else {
            res += 1ll * c[i] * c[(i + 1) % n];
            res += 1ll * c[i] * c[((i - 1) % n + n) % n];
            res += 1ll * c[i] * (ktot - (mark[(i + 1) % n]?c[(i + 1) % n] : 0) -
                   (mark[((i - 1) % n + n) % n]?c[((i - 1) % n + n) % n] : 0));
            //cout << c[(i + 1) % n] + c[((i - 1) % n + n) % n] + ktot - (mark[(i + 1) % n]?c[(i + 1) % n] : 0) -
            //        (mark[((i - 1) % n + n) % n]?c[((i - 1) % n + n) % n] : 0) << '\n';
        }
    }

    cout << res / 2 << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}