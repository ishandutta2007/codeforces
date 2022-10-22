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

    if(m == 1) cout << min(2, n) << '\n';
    else if(m == n) cout << max(1, m - 1) << '\n';
    else {
        int l1 = m - 1;
        int l2 = n - m;
        if(l1 >= l2) cout << m - 1 << '\n';
        else cout << m + 1 << '\n';
    }

    return true;
}

int main() {

    //while(solve());
    solve();    

    return 0;
}