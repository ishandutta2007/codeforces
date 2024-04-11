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

#include <conio.h>

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

bool solve()
{
    int n, m;

    scanf("%d %d", &n, &m);

    vec< pair<int, int> > a(m);

    for(int i(0);i < m;i++) {
        int d, h;
        scanf("%d %d", &d, &h);
        a[i] = mp(d, h);
    }

    int ans;

    ans = max(a[0].first - 1 + a[0].second, n - a[m - 1].first + a[m - 1].second);

    for(int i(0);i < m - 1;i++) {
        int d1, h1, d2, h2;
        d1 = a[i].first;
        h1 = a[i].second;
        d2 = a[i + 1].first;
        h2 = a[i + 1].second;

        if(abs(h1 - h2) > d2 - d1) {
            puts("IMPOSSIBLE");
            return true;
        }

        int x1, y1, x2, y2;

        x1 = d1, y1 = h1;
        x2 = d2, y2 = h2;

        int delt1 = y1 - x1;
        int delt2 = y2 + x2;

        int tmp = (delt1 + delt2) / 2;

        ans = max(ans, tmp);
    }

    printf("%d\n", ans);

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}