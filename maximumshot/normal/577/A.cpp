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
    
    int n, x, ans = 0;

    cin >> n >> x;

    for(int i = 1;i * i <= x;i++) {
        if(x % i) continue;
        int j = x / i;
        if(1 <= i && i <= n && 1 <= j && j <= n) {
            ans++;  
            if(i != j) ans++;
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