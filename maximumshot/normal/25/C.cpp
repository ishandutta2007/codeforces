#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

int Abs (int x) {return (x >= 0?x : -x);}

const LL p = 157;

bool solve()
{   
    int n, k;
    LL ans = 0;

    scanf("%d", &n);

    vec< vec<int> > d(n, vec<int>(n));

    for(int i(0);i < n;i++) for(int j(0);j < n;j++) scanf("%d", &d[i][j]);

    scanf("%d", &k);

    for(int w, u, v, i(0);i < k;i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;

        ans = 0;

        for(int j(0);j < n;j++)
        {
            for(int q(j + 1);q < n;q++)
            {
                int d1, d2, d3, D;
                
                d1 = d[j][q];
                d2 = d[j][u] + w + d[v][q];
                d3 = d[j][v] + w + d[u][q];
                D = min(min(d1, d2), d3);
                ans += D;
                d[j][q] = d[q][j] = D;
            }
        }

        printf("%I64d\n", ans);
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}