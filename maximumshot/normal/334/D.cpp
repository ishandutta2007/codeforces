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

    scanf("%d %d", &n, &m);

    vec<bool> a(n + 1, 0), b(n + 1, 0);

    a[0] = b[0] = a[1] = a[n] = b[1] = b[n] = 1;

    for(int i(0);i < m;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x] = b[y] = 1;
    }

    vec< bool > ta(n + 1, 0), tb(n + 1, 0); 

    for(int i(2);i <= n - 1;i++) {
        if(a[i]) ta[i] = 0;
        else ta[i] = 1;
    }

    for(int i(2);i <= n - 1;i++) {
        if(b[i]) tb[i] = 0;
        else {
            tb[i] = 1;  
        }
    }

    cout << count(ALL(ta), true) + count(ALL(tb), true) - (n % 2 && ta[n / 2 + 1] && tb[n / 2 + 1]) << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}