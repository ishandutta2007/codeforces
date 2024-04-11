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
#include <iomanip>

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

const int NMAX = 4040;

bool solve() {

    LL s[NMAX][NMAX];

    for(int i = 0;i < NMAX;i++) {
        for(int j = 0;j < NMAX;j++) {
            s[i][j] = 0;
        }
    }

    s[0][0] = 1;

    for(int i = 1;i < NMAX;i++) {
        for(int j = 1;j < NMAX;j++) {
            s[i][j] = (s[i - 1][j - 1] + (LL)j * s[i - 1][j]) % base;
        }
    }

    LL ans = 0;
    int n;
    cin >> n;

    for(int i = 1;i <= n;i++) {
        ans = (ans + (LL)i * s[n][i]) % base;
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