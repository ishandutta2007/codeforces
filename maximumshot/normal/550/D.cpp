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
    int k;
    cin >> k;

    if(k % 2 == 0) {
        cout << "NO\n";
        return true;
    }

    if(k == 1) {
        cout << "YES\n2 1\n1 2\n";
        return true;
    }

    cout << "YES\n";

    int n = (2 * (k + 1) + 1);

    cout << (2 * (k + 1) + 1) * 2 << ' ';

    vec< vec<int> > g((2 * (k + 1) + 1) * 2, vec<int>((2 * (k + 1) + 1) * 2));

    for(int i(0);i < k + 1;i++) {
        for(int j(i + 1);j < k + 1;j++) {
            g[i][j] = g[j][i] = 1;
            g[i + k + 1][j + k + 1] = g[j + k + 1][i + k + 1] = 1;
        }
    }
    
    // [0 .. k] [k + 1 .. 2 * k + 1]
    // q = 2 * k + 2

    g[0][1] = g[1][0] = 0;

    g[2 * k + 2][0] = g[0][2 * k + 2] = 1;

    for(int j(k + 1), i(0);i < k / 2;i++, j += 2) {
        g[2 * k + 2][j] = g[j][2 * k + 2] = 1;
        g[2 * k + 2][j + 1] = g[j + 1][2 * k + 2] = 1;
        g[j][j + 1] = g[j + 1][j] = 0;
    }

    int delt = 2 * k + 3;

    for(int i(0);i < k + 1;i++) {
        for(int j(i + 1);j < k + 1;j++) {
            g[i + delt][j + delt] = g[j + delt][i + delt] = 1;
            g[i + k + 1 + delt][j + k + 1 + delt] = g[j + k + 1 + delt][i + k + 1 + delt] = 1;
        }
    }
    
    g[0 + delt][1 + delt] = g[1 + delt][0 + delt] = 0;

    g[2 * k + 2 + delt][0 + delt] = g[0 + delt][2 * k + 2 + delt] = 1;

    for(int j(k + 1), i(0);i < k / 2;i++, j += 2) {
        g[2 * k + 2 + delt][j + delt] = g[j + delt][2 * k + 2 + delt] = 1;
        g[2 * k + 2 + delt][j + 1 + delt] = g[j + 1 + delt][2 * k + 2 + delt] = 1;
        g[j + delt][j + 1 + delt] = g[j + 1 + delt][j + delt] = 0;
    }

    g[1][1 + delt] = g[1 + delt][1] = 1;

    int cnt = 0;
    for(int i(0);i < (int)g.size();i++) {
        for(int j(i + 1);j < (int)g.size();j++) {
            if(g[i][j]) cnt++;
        }
    }

    cout << cnt << '\n';

    for(int i(0);i < (int)g.size();i++) {
        for(int j(i + 1);j < (int)g.size();j++) {
            if(g[i][j]) cout << i + 1 << ' ' << j + 1 << '\n';
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