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

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
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
    int n, m;

    cin >> n >> m;

    vec<string> a(n);

    for(int i(0);i < n;i++) {
        cin >> a[i];
    }

    vec< vec<bool> > eat(n, vec<bool>(m, 0));
    vec<bool> col(m), str(n);

    for(int i(0);i < n;i++) {
        for(int j(0);j < m;j++) {
            if(a[i][j] == '.') continue;
            col[j] = str[i] = 1;
        }
    }

    for(int i(0);i < n;i++) {
        if(str[i]) continue;
        for(int j(0);j < m;j++) {
            eat[i][j] = 1;
        }
    }

    for(int j(0);j < m;j++) {
        if(col[j]) continue;
        for(int i(0);i < n;i++) {
            eat[i][j] = 1;
        }
    }

    int ans = 0;
    for(int i(0);i < n;i++) {
        for(int j(0);j < m;j++) {
            ans += eat[i][j];
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