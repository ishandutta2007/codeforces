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

vec< vec<int> > g;
vec< bool > used; 
vec< int > tops;

void dfs(int v)
{
    used[v] = 1;

    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
    tops.push_back(v);
}

bool solve()
{
    g.resize(26);
    used.assign(26, 0);

    int n;

    cin >> n;

    vec<string> a(n);

    for(int i(0);i < n;i++) cin >> a[i];

    string ans = "";
    map<char, int> pos;

    for(int i(0);i < 26;i++) pos[char(i + 'a')] = -1;

    for(int i(0);i < n - 1;i++)
    {
        int sa = (int)a[i].size();
        int sb = (int)a[i + 1].size();  
        int s = min(sa, sb);

        if(a[i].substr(0, s) == a[i + 1].substr(0, s))
        { 
            if(sa > sb) 
            {
                puts("Impossible");
                return true;
            }
        }else
        {
            int q = 0;
            for(q;q < s;q++) if(a[i][q] != a[i + 1][q]) break;
            int x, y;
            x = int(a[i][q] - 'a');
            y = int(a[i + 1][q] - 'a');
            g[y].push_back(x);
        }
    }

    for(int i(0);i < 26;i++) if(!used[i]) dfs(i);

    for(int i(0);i < int(tops.size());i++)
        pos[char(tops[i] + 'a')] = i;
    
    for(int i(0);i < n - 1;i++)
    {
        int sa = (int)a[i].size();
        int sb = (int)a[i + 1].size();  
        int s = min(sa, sb);

        if(a[i].substr(0, s) == a[i + 1].substr(0, s))
        { 
            if(sa > sb) 
            {
                puts("Impossible");
                return true;
            }
        }else
        {
            int q = 0;
            for(q;q < s;q++) if(a[i][q] != a[i + 1][q]) break;
            
            if(pos[a[i][q]] > pos[a[i + 1][q]])
            {
                puts("Impossible");
                return true;    
            }
        }
    }

    for(int i(0);i < 26;i++) if(!used[i]) ans += char(i + 'a');

    for(int i(0);i < (int)tops.size();i++) ans += char(tops[i] + 'a');

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}