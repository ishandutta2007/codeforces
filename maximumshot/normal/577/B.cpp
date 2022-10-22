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

bool solve() {
    
    int n, m;

    scanf("%d %d", &n, &m);

    vec< int > a(n + 1);
    vec< int > g(m);
    vec< vec< char > > can(m, vec< char >(m, 0));

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        g[a[i] % m]++;
    }

    bool flag = 0;

    for(int i = 0;i < m && !flag;i++) {
        if(i > 0) can[i] = can[i - 1];
        for(int j = 1;j <= g[i];j++) {
            can[i][(j * i) % m] = 1;
        }
        for(int j = 0;j < m;j++) {
            // can[i][j] ? 
            for(int q = 1;q <= g[i];q++) {
                int back = j - q * i;
                back = (back % m + m) % m;
                if(i > 0 && can[i - 1][back]) can[i][j] = 1;
            }
        }
        if(can[i][0]) flag = 1;
    }

    cout << (flag || can[m - 1][0]?"YES":"NO") << '\n';

    return true;
}

int main() {
    
    //while(solve());
    solve();  

    return 0;
}