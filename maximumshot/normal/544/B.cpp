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
    int n, k;

    cin >> n >> k;

    vec< vec<bool> > a(n, vec<bool>(n, 0));

    int c = 0;
    for(int i(0);i < n && c < k;i++) {
        for(int j(0);j < n && c < k;j++) {
            if((i + j) & 1) continue;
            a[i][j] = 1;
            c++;
        }
    }

    if(c < k) {
        puts("NO");
    }else { 
        puts("YES");
        for(auto i : a) {
            for(auto j : i) {
                putchar(j?'L':'S');
            }
            putchar('\n');
        }
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}