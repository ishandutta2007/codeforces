#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}

using namespace std;

bool solve()
{
    int n;

    cin >> n;

    vec<int> ans(n);
    set<int> s;

    map<int, int> g, gt;
    map<int, bool> used;

    for(int a, b, i(0);i < n;i++)
    {
        cin >> a >> b;
        g[a] = b;
        used[a] = 1;
        gt[b] = a;
        s.insert(a);
        s.insert(b);
    }

    
    int pos = 1, ind = 0;

    while(pos < n)
    {
        ind = g[ind];
        ans[pos] = ind;
        pos += 2;
        s.erase(ind);
    }

    if(n % 2 == 0)
    {
        pos = n - 2;

        ind = 0;
        while(pos >= 0)
        {
            ind = gt[ind];
            ans[pos] = ind;
            pos -= 2;
        }
    }else
    {
        for(set<int>::iterator i = s.begin();i != s.end();i++)
        {
            if(!used[*i]) {ind = *i;break;}
        }

        pos = n - 1;

        while(pos >= 0)
        {
            ans[pos] = ind;
            ind = gt[ind];
            pos -= 2;
        }
    }
    

    for(int i(0);i < n;i++) cout << ans[i] << ' ';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}