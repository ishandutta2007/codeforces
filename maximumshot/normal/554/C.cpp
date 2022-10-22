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

bool solve()
{
    LL c[1005][1005];

    for(int i = 0;i < 1005;i++) for(int j = 0;j < 1005;j++) c[i][j] = 0;

    for(int i = 0;i < 1005;i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j < i;j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % base;
        }
    }

    LL ans = 1;
    int n, sum = 0;
    scanf("%d", &n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        ans = (ans * c[sum + x - 1][x - 1]) % base;
        sum += x;
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