#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <tuple>
#include <stack>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define mp make_pair
#define mt make_tuple
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;

bool solve() {

    int n;

    cin >> n;

    vec< vec< int > > a(2 * n + 1, vec< int >(2 * n + 1));

    for(int i = 2;i <= 2 * n;i++) {
        for(int j = 1;j < i;j++) {
            cin >> a[i][j];
        }
    }
    vec< int > ans(2 * n + 1, -1); 

    while(1) {
        int uu, vv, u_value = -1;
        uu = -1;
        for(int i = 1;i <= 2 * n;i++) {
            for(int j = 1;j < i;j++) {
                if(ans[i] != -1 || ans[j] != -1) continue;
                if(a[i][j] > u_value) u_value = a[i][j], uu = i, vv = j;
            }
        }
        if(uu == -1) break;
        int v_value = -1;
        for(int j = 1;j < vv;j++) {
            if(ans[j] != -1) continue;
            v_value = max(v_value, a[vv][j]);
        }
        if(v_value <= u_value) {
            ans[uu] = vv;
            ans[vv] = uu;
            a[uu][vv] = -2;
        }
    }

    for(int i = 1;i <= 2 * n;i++) cout << ans[i] << ' ';
    cout << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}