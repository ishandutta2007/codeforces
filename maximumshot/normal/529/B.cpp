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
    vec<LL> x;

    for(int i(0);i < n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(ALL(a));

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
            if(min(a[j].first, a[j].second) > i) f = 0;

        if(!f) continue;

        int cnt = 0;
        
        x.clear();

        for(int j(0);j < n;j++)
        {
            if(a[j].second > i) cnt++, s += a[j].second;
            else
            {
                s += a[j].first;
                if(a[j].first <= a[j].second || a[j].first > i) continue;
                x.push_back(a[j].second - a[j].first);
            }
        }
            
        sort(ALL(x));

        if(cnt * 2 > n) continue;
        
        for(int j(0);j < (int)x.size() && (cnt + 1) * 2 <= n;j++, cnt++) s += x[j];

        //cout << i << ' ' << s << '\n';

        ans = min(ans, (LL)i * s);
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