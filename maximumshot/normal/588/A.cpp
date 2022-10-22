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
    cin >> n;
    
    int a, p;
    
    int ans = 0, mn = inf;
    
    for(int i = 0;i < n;i++) {
        cin >> a >> p;
        mn = min(mn, p);
        ans += mn * a;
    }
    
    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}