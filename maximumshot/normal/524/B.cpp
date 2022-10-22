
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
#define go(x, y) q.push(mp((x), (y))), ans[(x)][(y)] = 1;
  
typedef long long LL;
typedef long double LD;
  
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
 
bool solve()
{
    int n;
    cin >> n;
    vec< pair<LL, LL> > a(n);
    
    for(int i(0);i < n;i++) 
        cin >> a[i].first >> a[i].second;
    
    LL ans = inf64;

    for(LL i(0);i <= 1000;i++)
    {
        bool f = 0;
        for(int j(0);j < n && !f;j++) if(a[j].first == i || a[j].second == i) f = 1;
        if(!f) continue;
        LL s;
        s = 0;
        f = 1;
        for(int j(0);j < n;j++)
        {
            if(a[j].first > a[j].second) swap(a[j].first, a[j].second);
            if(a[j].first > i) f = 0;
        }

        if(!f) continue;

        for(int j(0);j < n;j++)
        {
            if(a[j].second < i) s += a[j].first;
            else if(a[j].second > i) s += a[j].second;
            else s += a[j].first;
        }

        ans = min(ans, i * s);
    }

    cout << ans << '\n';

    return true;
}
  
int main()
{
    //while(solve());
    solve();
  
    return 0;
}