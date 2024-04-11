#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back

struct part
{
       ll res, num;
};

bool cmp(part a, part b)
{
     return a.res > b.res || a.res == b.res && a.num < b.num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll n, t1, t2, k;
    
    cin >> n >> t1 >> t2 >> k;
    
    part p[n];
    
    for(int i = 0; i < n; ++i)
    {
            ll a, b;
            cin >> a >> b;
            ll res1 = (100 - k) * a * t1 + 100 * b * t2, res2 = (100 - k) * b * t1 + 100 * t2 * a;
            p[i].num = i + 1;
            p[i].res = max(res1, res2);
    }
    
    sort(p, p + n, cmp);
    
    for(int i = 0; i < n; ++i)
    {
            int nn = p[i].num;
            ll res = p[i].res;
            printf("%d ", nn);
            printf("%d.", (int)(res / 100));
            printf("%02d\n", (int)(res % 100));
    }
    cin >> n;  
    
    return 0;
}