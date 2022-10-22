#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const int inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

bool solve() 
{
    int n, l, r, x;

    cin >> n >> l >> r >> x;

    vec<int> a(n);
    for(int i(0);i < n;i++) {
        cin >> a[i];
    }

    int ans = 0;

    for(int mask = 0;mask < (1 << n);mask++) {
        int cnt = 0;
        for(int j(0);j < n;j++) {
            if((1 << j) & mask) cnt++;
        }

        if(cnt < 2) continue;
        
        LL sum = 0, mx, mn;
        mx = -inf64;
        mn = +inf64;
        for(int j(0);j < n;j++) {
            if((1 << j) & mask) {
                sum += a[j];
                mx = max(mx, (LL)a[j]);
                mn = min(mn, (LL)a[j]);
            }
        }

        if(sum < l) continue;
        if(sum > r) continue;
        if(mx - mn < x) continue;
        ans++;
    }

    cout << ans << '\n';

    return true;
}   

int main()  
{
    //while(solve());   
    solve();

    return 0;
}