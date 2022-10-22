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

string read()
{
    char buf[200100];
    scanf("%s", &buf);
    return buf;
}

bool solve()
{
    int n;
    scanf("%d", &n);

    string s, t;

    s = read();
    t = read();

    LL ans = 0;
    for(int i(0);i < n;i++) ans += (s[i] != t[i]);

    vec< vec<int> > g(26, vec<int>(26, -1));

    for(int i(0);i < n;i++)
    {
        if(s[i] == t[i]) continue;
        g[t[i] - 'a'][s[i] - 'a'] = i;
    }

    for(int i(0);i < n;i++)
    {
        if(s[i] == t[i]) continue;
        int u, v;
        u = s[i] - 'a';
        v = t[i] - 'a';

        if(g[u][v] != -1)
        {
            printf("%I64d\n%d %d\n", ans - 2, i + 1, g[u][v] + 1);
            return true;
        }
    }

    for(int i(0);i < n;i++)
    {
        if(s[i] == t[i]) continue;
        int u, v;
        u = s[i] - 'a';
        v = t[i] - 'a';
        int pos = -1;
        for(int j(0);j < 26;j++) if(g[u][j] != -1) {pos = j; break;}
        if(pos != -1)
        {
            printf("%I64d\n%d %d\n", ans - 1, i + 1, g[u][pos] + 1);
            return true;
        }
    }

    printf("%I64d\n-1 -1", ans);

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}