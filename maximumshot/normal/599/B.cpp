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
    
    int n, m;

    scanf("%d %d", &n, &m);

    vec< int > f(n + 1), b(m + 1);
    vec< int > vis(n + 1, 0);

    for(int i = 1;i <= n;i++) scanf("%d", &f[i]), vis[f[i]]++;
    for(int i = 1;i <= m;i++) scanf("%d", &b[i]);

    for(int i = 1;i <= m;i++) {
        if(!vis[b[i]]) {
            puts("Impossible");
            return true;
        }
    }

    for(int i = 1;i <= m;i++) {
        if(vis[b[i]] > 1) {
            puts("Ambiguity");
            return true;
        }
    }

    puts("Possible");

    vec< int > key(n + 1);

    for(int i = 1;i <= n;i++) key[f[i]] = i;

    for(int i = 1;i <= m;i++) {
        printf("%d ", key[b[i]]);
    }

    puts("");

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}