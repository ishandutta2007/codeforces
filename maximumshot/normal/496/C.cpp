#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    int n, m, ans = 0;

    cin >> n >> m;

    vec<string> mat(n);
    vec<bool> used(m, 1);

    for(int i(0);i < n;i++) cin >> mat[i];

    for(int z(0);z < m;z++)
    {
        for(int i(0);i < n - 1;i++)
        {
            for(int j(0);j < m;j++)
            {
                if(!used[j]) continue;
                if(mat[i][j] < mat[i + 1][j]) break;
                if(mat[i][j] > mat[i + 1][j]) ans++, used[j] = 0;
            }
        }
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