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

    int n, t;

    cin >> n >> t;

    vec< int > a(n + 1), cnt(330, 0); 

    for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]]++;
    
    int k = min(t, n), mx = *max_element(ALL(cnt));

    mx *= (t - k);

    a.resize(k * n + 1);

    for(int i = n + 1;i <= k * n;i++) a[i] = a[i - n];

    vec< int > dp(k * n + 1);

    for(int i = 1;i <= k * n;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    mx += *max_element(ALL(dp));

    cout << mx << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}