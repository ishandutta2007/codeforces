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
const LL base = inf * 1000ll + 17;
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
    int n;

    scanf("%d", &n);

    vec<int> ans;

    for(int i(0);i < n;i++) {
        bool ok = 1;
        for(int x, j(0);j < n;j++) {
            scanf("%d", &x);
            if(x == 1 || x == 3) {
                ok = 0;
            }
        }
        if(ok) {
            ans.push_back(i);
        }
    }

    n = (int)ans.size();

    printf("%d\n", n);

    for(int x, i(0);i < n;i++) {
        x = ans[i];
        printf("%d ", x + 1);
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}