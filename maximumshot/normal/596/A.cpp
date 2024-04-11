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

bool solve()
{
    int n;

    cin >> n;

    vec< pair< int, int > > a(n);

    for(int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;

    if(n >= 3) {
        int mnx, mxx, mny, mxy;
        mnx = mny = inf;
        mxx = mxy = -inf;
        for(int i = 0;i < n;i++) {
            mnx = min(mnx, a[i].first);
            mxx = max(mxx, a[i].first);
            mny = min(mny, a[i].second);
            mxy = max(mxy, a[i].second);
        }
        cout << (mxx - mnx) * (mxy - mny) << '\n';
    }else if(n == 1) cout << -1 << '\n';
    else { // n == 2
        if(a[0].first == a[1].first || a[0].second == a[1].second) cout << -1 << '\n';
        else cout << abs(a[0].first - a[1].first) * abs(a[0].second - a[1].second) << '\n';
    }

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}