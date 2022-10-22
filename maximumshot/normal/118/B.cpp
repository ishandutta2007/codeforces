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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int Abs(int x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;

    cin >> n;

    vec< string > ans(2 * n + 1, string(2 * n + 1, ' '));

    for(int i(0);i <= n;i++)
    {
        for(int pos(n), pos2(n), j(i);j <= n;j++, pos--, pos2++) ans[j][pos] = ans[j][pos2] = char(i + '0');
        for(int pos(i + 1), pos2(2 * n - 1 - i), j(n + 1);j < 2 * n + 1 - i;j++, pos++, pos2--) ans[j][pos] = ans[j][pos2] = char(i + '0');
    }

    for(int i(0);i < 2 * n + 1;i++) while(ans[i].back() == ' ') ans[i].pop_back();

    for(int i(0);i < 2 * n + 1;i++)
    {
        for(int j(0);j < (int)ans[i].size();j++)
        {
            cout << ans[i][j];
            if(j < (int)ans[i].size() - 1) cout << ' ';
        }
        cout << '\n';
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}