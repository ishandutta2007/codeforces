#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

const LL N = 100100;

bool solve()
{
    int n, k, c;

    cin >> n >> k;
    
    vec< vec<int> > g(n, vec<int>(n, 0));

    for(int i(0);i < n;i++)
    {
        c = 0;
        for(int j(0);j < n && c < k;j++)
        {
            if(i == j || g[j][i]) continue;
            c++;
            g[i][j] = 1;
        }
        
        if(c < k) {cout << -1 << '\n'; return true;}
    }

    vec< pair<int, int> > ans; 

    c = 0;

    for(int i(0);i < n;i++)
    {
        for(int j(0);j < n;j++)
        {
            if(g[i][j]) ans.push_back(mp(i, j)), c++;
        }
    }

    cout << c << '\n';

    for(int i(0);i < c;i++) cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}