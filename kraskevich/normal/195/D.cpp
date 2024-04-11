#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define FORN for(int i = 0; i < n; ++i)
#define PB push_back

struct event 
{
       i64 u, d;
       event(i64 xx = 0, i64 bb = 0)
       {
                 u = xx;
                 d = bb;
       }
};

bool cmp(event a, event b)
{
     if(a.u * a.d >= 0 && b.u * b.d <= 0)
            return false;
     if(a.u * a.d <= 0 && b.u * b.d >= 0)
            return true;
     if(a.u * a.d < 0)
            return max(a.u, -a.u) * max(b.d, -b.d) > max(b.u, -b.u) * max(a.d, -a.d);
     return max(a.u, -a.u) * max(b.d, -b.d) < max(b.u, -b.u) * max(a.d, -a.d);
}

bool eq(event a, event b)
{
     return a.u * b.d == b.u * a.d;
}     
           
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    vector<event> e;
    
    for(int i = 0; i < n; ++i)
    {
            i64 k, b;
            cin >> k >> b;
            if(!k)
                  continue;
            e.push_back(event(-b, k));
    }
    
    if(!e.size())
    {
                 cout << 0;
                 return 0;
    }
    
    int ans = 1;
    
    sort(e.begin(), e.end(), cmp);
    
    for(int i = 1; i < e.size(); ++i)
            if(!eq(e[i], e[i - 1]))
                         ++ans;
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}