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

vec<int> par, size;

int find(int x)
{
    return (x == par[x]?x : par[x] = find(par[x]));
}

void un(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if(size[pa] == size[pb])
        par[pa] = pb, size[pb]++;
    else
    {
        if(size[pa] > size[pb]) swap(pa, pb);
        par[pa] = pb;
    }
}

bool solve()
{   
    int n;

    scanf("%d", &n);

    par.resize(n);
    size.resize(n, 1);
    
    vec< pair<int, int> > close, open;

    for(int i(0);i < n;i++) par[i] = i;

    for(int u, v, i(0);i < n - 1;i++)
    {
        scanf("%d %d", &u, &v);
        u--, v--;

        if(find(u) == find(v)) close.push_back(mp(u, v));
        else un(u, v);
    }

    for(int i(0);i < n;i++) if(find(i) != find(0)) open.push_back(mp(0, i)), un(i, 0);
    
    printf("%d\n", (int)close.size());

    for(int i(0);i < (int)close.size();i++) printf("%d %d %d %d\n", close[i].first + 1, close[i].second + 1, open[i].first + 1, open[i].second + 1);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}