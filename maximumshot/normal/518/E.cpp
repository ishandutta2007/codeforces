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

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

LL _abs(LL x) 
{
    return (x >= 0ll?x : -x);
}

int n, k;

LL read()
{
    string a;
    cin >> a;

    if(a[0] == '?') return inf64;

    LL x = 0;

    for(int i(a[0] == '-'?1 : 0);i < (int)a.size();i++) x = x * 10 + a[i] - '0';

    return x * (a[0] == '-'?-1ll : 1ll);
}

bool f;

void up(vec<LL> & a)
{
    vec<int> pos;

    int ind = 0, sz = (int)a.size();

    //for(int i(0);i < sz;i++) cout << a[i] << ' ';
    //cout << '\n';

    for(int i(0);i < sz;i++)
    {
        if(a[i] == inf64) continue;
        pos.push_back(i);
    }

    if(pos.empty())
    {
        for(int j(-sz / 2), i(0);i < sz;i++, j++) a[i] = j;
        return;
    }

    for(LL j(min(a[pos[0]] - 1, (LL)(pos[0]) / 2)), i(pos[0] - 1);i >= 0;i--, j--) a[i] = j;    
    for(LL j(max(a[pos.back()] + 1, (LL)-(sz - pos.back() - 1) / 2)), i(pos.back() + 1);i < sz;i++, j++) a[i] = j;
        
    for(int i(0);i < (int)pos.size() - 1;i++)
    {
        int x, y;
        x = pos[i];
        y = pos[i + 1];

        // [x + 1 .. y - 1]

        f &= (a[y] > a[x]); 
        f &= (y - x - 1 <= a[y] - a[x] - 1);
        if(!f) break;

        if(a[x] >= 0)
        {
            for(int j(x + 1);j <= y - 1;j++) a[j] = a[j - 1] + 1;
        }else if(a[y] <= 0)
        {
            for(int j(y - 1);j >= x + 1;j--) a[j] = a[j + 1] - 1;
        }else
        {
            if(_abs(a[x]) <= _abs(a[y]))
            {
                for(LL cur(max(a[x] + 1, (LL)-(y - x - 1) / 2)), j(x + 1);j <= y - 1;j++, cur++) a[j] = cur; 
            }else
            {
                for(LL cur(min(a[y] - 1, (LL)( y - x - 1) / 2)), j(y - 1);j >= x + 1;j--, cur--) a[j] = cur;
            }
        }
    }
}

bool solve()
{
    f = 1;  

    cin >> n >> k;

    vec<LL> a(n), tmp;

    for(int i(0);i < n;i++) a[i] = read();

    //cout << "ok_init\n";
    //for(int i(0);i < n;i++) cout << a[i] << ' ';
    //cout << '\n';

    for(int i(0);i < k;i++)
    {
        tmp.clear();
        for(int j(i);j < n;j += k) tmp.push_back(a[j]);

        up(tmp);

        if(!f)
        {
            puts("Incorrect sequence");
            return true;
        }

        for(int z(0), j(i);j < n;j += k, z++) a[j] = tmp[z];
    }

    for(int i(0);i < n;i++) cout << a[i] << ' ';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}