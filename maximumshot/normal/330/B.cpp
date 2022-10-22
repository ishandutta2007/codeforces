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

    scanf("%d %d", &n, &m);

    vec< vec<int> > g(n);

    for(int u, v, i(0);i < m;i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    printf("%d\n", n - 1);

    for(int i(0);i < n;i++) {
        if((int)g[i].size() > 0) continue;
        for(int j(0);j < n;j++) {
            if(i == j) continue;
            printf("%d %d\n", i + 1, j + 1);
        }
        return true;
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}