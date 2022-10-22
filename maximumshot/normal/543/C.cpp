#include <iostream>
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

#include <memory>

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

void read(string & s) {
    char buffer[25];
    scanf("%s", &buffer);
    s = buffer;
}

bool solve() {

    int n, m;

    scanf("%d %d", &n, &m);

    vec< string > s(n);
    for(int i = 0;i < n;i++) read(s[i]);
    vec< vec< int > > a(n, vec< int >(m, 0));   
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) scanf("%d", &a[i][j]);

    vec< int > dp(1 << n, inf);
    vec< vec< int > > cur(n + 1);

    for(int c = 0, mask = 0;mask < (1 << n);mask++, c = 0) {
        for(int i = 0;i < n;i++) if((1 << i) & mask) c++;
        cur[c].push_back(mask);
    }

    vec< vec< int > > sv(n, vec< int >(m));
    vec< vec< int > > value(n, vec< int >(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            int mx = -inf;
            for(int k = 0;k < n;k++) {
                if(s[k][j] == s[i][j]) {
                    mx = max(mx, a[k][j]);
                    value[i][j] += a[k][j];
                    sv[i][j] ^= (1 << k);
                }
            }
            value[i][j] -= mx;
        }
    }

    dp[0] = 0;

    for(int c = 1;c <= n;c++) {
        for(int it = 0;it < (int)cur[c].size();it++) {
            int mask = cur[c][it], lower;
            for(int i = 0;i < n;i++) {
                if((1 << i) & mask) { 
                    lower = i;
                    break;
                }
            }

            for(int j = 0;j < m;j++) {
                dp[mask] = min(dp[mask], dp[mask ^ (1 << lower)] + a[lower][j]);
                dp[mask] = min(dp[mask], dp[mask & (mask ^ sv[lower][j])] + value[lower][j]);
            }
        }
    }

    printf("%d\n", dp[(1 << n) - 1]);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}