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
typedef pair<int, int> pii;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

struct ev
{
    int x, type, id;
    ev()
    {
        x = -1;
        type = -1;
        id = -1;
    }   

    ev(int _x, int _id, int _type)
    {
        x = _x;
        type = _type;
        id = _id;
    }

    bool operator < (const ev & b)
    {
        return (x < b.x || (x == b.x && type < b.type));
    }
};

int gen(string x)
{
    int h, m, s;
    for(auto & i : x) i -= '0';
    h = x[0] * 10 + x[1];
    m = x[3] * 10 + x[4];
    s = x[6] * 10 + x[7];
    return (h * 3600 + m * 60 + s);
}

bool solve()
{
    int n, m, t;

    scanf("%d %d %d", &n, &m, &t);

    vec<int> ans(n);
    vec<ev> e;

    for(int i(0);i < n;i++)
    {
        string s;
        cin >> s;
        int x = gen(s);
        e.push_back(ev(x, i,0));
        e.push_back(ev(x + t - 1, i, 1));
    }
    
    sort(ALL(e));

    set<int> s;
    multiset<int> ms;

    int num = 0;

    vec<int> c(1e5, 0);

    bool ok = 0;

    for(int i(0);i < 2 * n;i++)
    {
        if((int)s.size() == m) ok = 1;
        int id = e[i].id;
        if(e[i].type == 0)
        {
            if((int)s.size() < m) ans[id] = ++num, s.insert(ans[id]), c[ans[id]]++;
            else ok = 1, ans[id] = *(--s.end()), c[ans[id]]++;
        }else 
        {
            c[ans[id]]--;
            if(!c[ans[id]]) s.erase(ans[id]);
        }
    }
    
    if(!ok)
        puts("No solution");
    else 
    {
        printf("%d\n", *max_element(ALL(ans)));
        for(auto i : ans) printf("%d\n", i);
    }
    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}