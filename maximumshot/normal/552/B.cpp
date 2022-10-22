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

#include <conio.h>

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

LL get(int x) {
    LL ans = 0;
    while(x) {
        ans++;
        x /= 10;
    }
    return ans;
}

LL Slow(int n) {
    LL ans = 0;
    for(int i(1);i <= n;i++) ans += get(i);
    return ans;
}

bool solve() 
{
    LL ans = 0;

    int n;

    cin >> n;

    if(n <= 9) {
        cout << n << '\n';
        return true;
    }

    for(int i(1);i <= 11;i++) {
        LL l = 1, r = 1;
        for(int j(0);j + 1 < i;j++) l *= 10ll;
        r = l * 10ll;
        // [l .. r)
        if(l > n) break;
        if(r - 1 <= n) {
            if(i == 1) ans += 9;
            else ans += LL(i) * (r - l);
        }else {
            ans += LL(i) * (n - l + 1);
        }
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