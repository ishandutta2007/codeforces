#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <complex>
#include <unordered_map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
    
    int n, d;

    scanf("%d %d", &n, &d);

    vec< pair< int, int> > a(n + 1);

    for(int m, s, i = 1;i <= n;i++) {
        scanf("%d %d", &m, &s);
        a[i] = mp(m, s);
    }

    sort(a.begin() + 1, a.end());

    vec< ll > sum(n + 1);
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i].second;

    ll ans = -1;

    for(int i = 1;i <= n;i++) {
        int bl, br, bm, bp;
        bl = i, br = n;
        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(a[bm].first - a[i].first < d) bl = bm;
            else br = bm - 1;
        }
        if(a[br].first - a[i].first < d) bp = br;
        else bp = bl;
        ans = max(ans, sum[bp] - sum[i - 1]);
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}