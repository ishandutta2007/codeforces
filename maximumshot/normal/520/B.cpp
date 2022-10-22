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

bool solve()
{
    int n, m, ans = inf;

    cin >> n >> m;

    if(n >= m)
    {
        cout << n - m << '\n';
        return true;
    }

    vec<int> d(1e6, inf);
    queue<int> q;

    d[n] = 0;
    q.push(n);
    
    vec<bool> in(1e6, 0);

    in[n] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        in[x] = 0;

        if(x > 1)
        {
            if(d[x - 1] > d[x] + 1)
            {
                d[x - 1] = d[x] + 1;
                
                if(!in[x - 1]) 
                    in[x - 1] = 1,
                    q.push(x - 1);
            }
        }

        if(x > m) continue;

        if(d[2 * x] > d[x] + 1)
        {
            d[2 * x] = d[x] + 1;
        
            if(!in[2 * x])
                in[2 * x] = 1,
                q.push(2 * x);
        }
    }

    cout << d[m] << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}