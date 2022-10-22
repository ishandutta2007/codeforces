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
    string a, b;

    cin >> a >> b;

    int cnt = 0, n = (int)a.size();
    
    for(int i(0);i < n;i++) {
        if(a[i] != b[i]) {
            cnt++;
        }
    }

    if(cnt % 2) {
        puts("impossible");
        return true;
    }

    int x = 0;

    for(int i(0);i < n;i++) {
        if(a[i] == b[i]) {
            cout << a[i];
        }else {
            if(x < cnt / 2) {
                cout << a[i];
                x++;
            }else {
                cout << b[i];
            }
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