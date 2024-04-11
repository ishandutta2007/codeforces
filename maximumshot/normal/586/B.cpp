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
    
    int n;

    scanf("%d", &n);

    vec< vec< int > > a(3, vec< int >(n));
    vec< int > b(n + 1);

    for(int i = 1;i <= 2;i++) {
        for(int j = 1;j < n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
    }

    int ans = inf;

    for(int f = 1;f <= n;f++) {
        for(int s = 1;s <= n;s++) {
            if(f == s) continue;
            int sum = 0;
            for(int j = f;j < n;j++) sum += a[2][j];
            sum += b[f];
            for(int j = 1;j < f;j++) sum += a[1][j];
            for(int j = 1;j < s;j++) sum += a[1][j];
            sum += b[s];
            for(int j = s;j < n;j++) sum += a[2][j];
            ans = min(ans, sum);
        }
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}