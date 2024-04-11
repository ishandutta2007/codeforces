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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() {
    
    int n, m;

    cin >> n >> m;

    vec< int > c(n + 1, 0), t, g(m + 1);

    for(int i = 1;i <= m;i++) {
        t.clear();
        t.resize(n + 1, 0);
        for(int j = 1;j <= n;j++) cin >> t[j];
        int ans = -1;
        for(int j = 1;j <= n;j++) {
            if(ans == -1 || t[ans] < t[j]) ans = j;
        }
        g[i] = ans;
        c[ans]++;
    }

    int ans = -1;
    for(int i = 1;i <= m;i++) {
        if(ans == -1) ans = g[i];
        else if(c[ans] < c[g[i]]) ans = g[i];
        else if(c[ans] == c[g[i]] && ans > g[i]) ans = g[i];
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();    

    return 0;
}