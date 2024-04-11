// by maximumSHOT
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
#include <stdio.h>
#include <stack>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("NO"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0); 

LL Abs(LL x) {return (x >= 0?x : -x);}

int n;
string s;

int par[62 * 62], size[62 * 62], in[62 * 62], out[62 * 62];
vec<int> ans, g[62 * 62];
vec<bool> used;

int _get(char c)
{
    if(c >= '0' && c <= '9') return (c - '0');
    else if(c >= 'a' && c <= 'z') return (c - 'a' + 10);
    else return (c - 'A' + 36);
}

int get(string a)
{
    int x, y;
    x = _get(a[0]);
    y = _get(a[1]);
    return x * 62 + y;
}

int find(int x)
{
    return (par[x] == x?x : par[x] = find(par[x]));
}

void un(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if(size[pa] == size[pb]) par[pa] = pb, size[pb]++;
    else
    {
        if(size[pa] > size[pb]) swap(pa, pb);
        par[pa] = pb;
    }
}

char chr(int x)
{
    if(x < 10) return char(x + '0');
    else if(x < 36) return char(x + 'a' - 10);
    else return char(x + 'A' - 36);
}

void dfs(int v)
{
    while(!g[v].empty())
    {
        int x = g[v].back();
        g[v].pop_back();
        dfs(x);
    }
    ans.push_back(v);
}

bool solve()
{
    //freopen("substrcmp.in", "r", stdin);
    //freopen("substrcmp.out", "w", stdout);

    for(int i(0);i < 62 * 62;i++) size[i] = 1, par[i] = i;

    cin >> n;

    used.assign(62 * 62, 0);

    int Q = -1;

    for(int i(0);i < n;i++)
    {
        int x, y;
        cin >> s;

        x = get(s.substr(0, 2));
        
        if(Q == -1) Q = x;
        
        y = get(s.substr(1, 2));
        used[x] = used[y] = 1;

        g[x].push_back(y);
        in[y]++;
        out[x]++;
        un(x, y);
    }
    
    bool f = 0;
    for(int i(0);i < 62 * 62;i++) 
    {
        if(!used[i]) continue;
        if(par[i] != i) continue;
        if(f) {close();}
        else f = 1;
    }

    int x1, x2;
    x1 = x2 = -1;

    for(int i(0);i < 62 * 62;i++)
    {
        if(in[i] == out[i]) continue;

        if(in[i] - out[i] == 1) 
        {
            if(x1 != -1) {close();}
            x1 = i;
        }else if(in[i] - out[i] == -1)
        {
            if(x2 != -1) {close();}
            x2 = i;
        }else {close();}
    }

    //cout << chr(x1 / 62) << chr(x1 % 62) << '\n';

    if(x1 == -1 && x2 != -1 || x1 != -1 && x2 == -1) {close();}

    used.assign(62 * 62, 0);

    dfs(x2 != -1?x2 : Q);

    reverse(ALL(ans));

    puts("YES");

    int x, y;

    x = ans[0] / 62;

    cout << chr(x);
    
    for(int i(0);i < (int)ans.size();i++) 
    {
        x = ans[i] % 62;
        cout << chr(x);
    }

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}