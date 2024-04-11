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

    vec< int > a(n + 1), b(n + 1);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

    int mx = 0;

    for(int i = n;i >= 1;i--) {
        if(a[i] <= mx) b[i] = mx + 1 - a[i];
        else b[i] = 0;
        mx = max(mx, a[i]);
    }

    for(int i = 1;i <= n;i++) printf("%d ", b[i]);
    
    puts("");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}