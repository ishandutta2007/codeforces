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

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 17;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    map< pair<LL, LL>, int > a; 
    vec< set<int> > g, gt;

    int m;
    cin >> m;

    g.resize(m);
    gt.resize(m);

    vec< pair<LL, LL> > crd(m);

    for(int i(0);i < m;i++) 
    {
        cin >> crd[i].first >> crd[i].second;
        a[crd[i]] = i;
    }

    LL ans = 0;

    for(int i(0);i < m;i++)
    {
        for(int j = -1;j <= 1;j++)
        {
            LL x, y;
            x = crd[i].first + j;
            y = crd[i].second - 1;
            if(a.count(mp(x, y)))
            {
                g[i].insert(a[mp(x, y)]);
                gt[a[mp(x, y)]].insert(i);
            }
        }
    }
    
    set<int> s;

    for(int i(0);i < m;i++) s.insert(i);

    for(int i(0);i < m;i++) 
        if((int)g[i].size() == 1) 
            s.erase(*g[i].begin()); 
    
    for(int step(0), i(0);i < m && (int)s.size();i++, step ^= 1)
    {
        int id;
        if(step) id = *(s.begin());
        else id = *(--s.end());

        s.erase(id);

        for(auto j : gt[id])
        {
            g[j].erase(id);
            if((int)g[j].size() == 1)
                s.erase(*g[j].begin());
        }

        for(auto j : g[id])
        {
            gt[j].erase(id);
            s.insert(j);
            for(auto k : gt[j]) if((int)g[k].size() == 1) s.erase(j);
        }

        ans = (ans * m + id) % MOD;
    }

    //cout << '\n';

    cout << ans % MOD << '\n';

    return true;
}   

int main()
{
    //while(solve());
    solve();

    return 0;
}