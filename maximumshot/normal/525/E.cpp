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
const LL base = inf + 7;    

vec<LL> fact;
int n;
LL s;

vec< pair<LL, int> > get(const vec<LL> & a)
{
    LL sum = 0, cnt, tmp;
    vec< pair<LL, int> > ans;
    for(LL i(1);i < (1ll << (int)a.size());i++)
    {
        sum = 0;
        for(LL j(0);j < (int)a.size();j++)
            if((1ll << j) & i) 
                sum += a[j];

        ans.push_back(mp(sum, 0));

        for(LL k(i);k > 0;k = (k - 1) & i)
        {
            cnt = 0;
            tmp = sum;
            bool flag = 1;
            for(LL j(0);j < (int)a.size();j++)
            {
                if((1ll << j) & k)
                {
                    if(a[j] > 20 || fact[a[j]] > s)
                    {
                        flag = 0;
                        break;
                    }else
                    {
                        cnt++;
                        tmp = tmp - a[j] + fact[a[j]];
                    }
                }
            }

            if(flag) ans.push_back(mp(tmp, (int)cnt));
        }
    }

    return ans;
}

bool solve()
{
    int k;
    scanf("%d %d %I64d", &n, &k, &s);

    vec<LL> mas(n), a, b;
    fact.resize(21);
    fact[0] = 1ll;
    for(LL i(1);i <= 20;i++) fact[i] = fact[i - 1] * i;
    for(int i(0);i < n;i++) scanf("%I64d", &mas[i]);

    for(int i(0);i < n / 2;i++) a.push_back(mas[i]);
    for(int i(n / 2);i < n;i++) b.push_back(mas[i]);

    vec< pair<LL, int> > tl, tr;

    tl = get(a);
    tr = get(b);

    /*cout << '\n';
    for(int i(0);i < (int)tl.size();i++) cout << tl[i].first << ' ' << tl[i].second << '\n';
    cout << '\n';
    for(int i(0);i < (int)tr.size();i++) cout << tr[i].first << ' ' << tr[i].second << '\n';
    cout << '\n';*/

    sort(ALL(tl));
    sort(ALL(tr));

    while(!tl.empty() && tl.back().first > s) tl.pop_back();
    while(!tr.empty() && tr.back().first > s) tr.pop_back();

    LL ans = 0;

    for(int i(0);i < (int)tl.size();i++)
    {
        if(tl[i].first == s)
        {
            if(tl[i].second <= k)
                ans++;
        }else
        {
            int l, r;
            l = lower_bound(ALL(tr), mp(s - tl[i].first, 0)) - tr.begin();
            r = lower_bound(ALL(tr), mp(s - tl[i].first, k - tl[i].second + 1)) - tr.begin();
            if(l > r) swap(l, r);
            ans += r - l;
        }
    }

    for(int i(0);i < (int)tr.size();i++) 
        if(tr[i].first == s && tr[i].second <= k)
            ans++;

    cout << ans << '\n';

    return true;    
}
  
int main()
{
    //while(solve());
    solve();
  
    return 0;
}