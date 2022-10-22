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
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

bool solve() {
    
    int n;

    scanf("%d", &n);
    
    vec< int > a(n + 1), b, first(n + 1);

    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

    b = a;
    sort(b.begin() + 1, b.end());

    map< int, int > cnt;
    
    vec< int > can(n + 1, 0);

    for(int i = 1;i <= n;i++) {
        cnt[a[i]]++;
        cnt[b[i]]--;
        if(cnt[a[i]] == 0) cnt.erase(a[i]);
        if(cnt[b[i]] == 0) cnt.erase(b[i]);
        can[i] = (cnt.empty()?1 : 0);
    }
    
    vec< int > last(n + 1);
    int now = 0;

    for(int i = 1;i <= n;i++) {
        last[i] = now;
        if(can[i]) now = i;
    }

    vec< int > dp(n + 1);

    for(int i = 1;i <= n;i++) {
        dp[i] = dp[last[i]] + 1;
    }

    printf("%d\n", dp[n]);

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}