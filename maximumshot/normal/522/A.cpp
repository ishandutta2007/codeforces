#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

int n, ans = -inf;
map<string, vec<string> > g;

void to_low(string & a)
{
    for(int i(0);i < (int)a.size();i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] - 'A' + 'a';
    }
}

void dfs(string v, int H = 0)
{
    ans = max(ans, H);
    for(int i(0);i < (int)g[v].size();i++)
    {
        string to = g[v][i];
        dfs(to, H + 1);
    }
}

bool solve()
{
    cin >> n;

    for(int i(0);i < n;i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        
        to_low(a);
        to_low(c);

        g[c].push_back(a);
    }

    dfs("polycarp");

    cout << ans + 1 << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}