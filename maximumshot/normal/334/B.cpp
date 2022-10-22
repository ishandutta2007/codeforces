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
    vec< pair<int, int> > a(8); 
    vec<int> x, y;

    for(int i(0);i < 8;i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        a[i] = mp(X, Y);
        x.push_back(X);
        y.push_back(Y);
    }

    sort(ALL(x));
    sort(ALL(y));

    x.resize(unique(ALL(x)) - x.begin());
    y.resize(unique(ALL(y)) - y.begin());

    if((int)x.size() != 3 || (int)y.size() != 3) {
        puts("ugly");
        return true;
    }

    if(x[0] == x[1] || x[1] == x[2] || y[0] == y[1] || y[1] == y[2]) {
        puts("ugly");
        return true;
    }

    for(int i(0);i < 8;i++) {
        if(a[i].first == x[1] && a[i].second == y[1]) {
            puts("ugly");
            return true;
        }
    }

    for(int i(0);i < 3;i++) {
        for(int j(0);j < 3;j++) {
            if(i == 1 && j == 1) continue;
            bool ok = 0;
            for(int q(0);q < 8;q++) {
                ok |= (a[q] == mp(x[i], y[j]));
            }
            if(!ok) {
                puts("ugly");
                return true;
            }
        }
    }

    puts("respectable");

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}