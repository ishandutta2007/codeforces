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
#include <stack>

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

LL Abs (LL x) {return (x >= 0ll?x : -x);}

bool solve()
{
    int n, m, k;

    cin >> n >> m >> k;

    int mat[1100][1100];

    for(int i(0);i < 1100;i++) for(int j(0);j < 1100;j++) mat[i][j] = 0;

    for(int x, y, i(0);i < k;i++)
    {
        cin >> x >> y;
        mat[x][y] = 1;

        if(mat[x][y - 1] && mat[x - 1][y - 1] && mat[x - 1][y]) 
        {
            cout << i + 1 << '\n';
            return true;
        }

        if(mat[x - 1][y] && mat[x - 1][y + 1] && mat[x][y + 1])
        {
            cout << i + 1 << '\n';
            return true;
        }

        if(mat[x][y + 1] && mat[x + 1][y] && mat[x + 1][y + 1])
        {
            cout << i + 1 << '\n';
            return true;
        }

        if(mat[x][y - 1] && mat[x + 1][y - 1] && mat[x + 1][y])
        {
            cout << i + 1 << '\n';
            return true;
        }
    }

    cout << 0 << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}