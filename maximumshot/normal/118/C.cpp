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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int Abs(int x) {return (x >= 0?x : -x);}

bool solve()
{
    int n, k, mn = inf, cnt[10] = {0}, cur;
    string a, ans = "", b;

    cin >> n >> k >> a;
    
    for(int i(0);i < n;i++) cnt[a[i] - '0']++;

    for(int i(0);i < 10;i++)
    {
        if(cnt[i] >= k)
        {
            cout << 0 << '\n' << a << '\n';
            return true;
        }
    }

    vec< pair<int, int> > tmp, val[2];

    for(int i(0);i < 10;i++)
    {
        tmp.clear();
        val[0].clear();
        val[1].clear();
        b = a;
        cur = 0;
        for(int j(0);j < n;j++) 
        {
            if(int(a[j] - '0') == i) continue;
            tmp.push_back(mp(Abs(a[j] - '0' - i), j));
        }
        sort(ALL(tmp));
        
    /*  if(i == 5)
        {
            for(int j(0);j < (int)tmp.size();j++) cout << tmp[j].first << ' ';
            cout << '\n';
        }*/

        int Q = k - cnt[i];

        for(int j(0);j < (int)tmp.size() && Q;j++)
        {
            if(tmp[j].first > tmp[k - cnt[i] - 1].first) break;
            if(tmp[j].first == tmp[k - cnt[i] - 1].first)
            {
                if(i < int(a[tmp[j].second] - '0')) val[0].push_back(mp(tmp[j].second, tmp[j].first));
                else val[1].push_back(mp(tmp[j].second, tmp[j].first));
            }else
            {
                cur += tmp[j].first;
                b[tmp[j].second] = char(i + '0');
                Q--;
            }
        }

        sort(ALL(val[0]));
        sort(ALL(val[1]));
        reverse(ALL(val[1]));

        /*if(i == 5)
        {
            for(int j(0);j < (int)val[0].size();j++) cout << val[0][j].first << ' ';
            cout << '\n';
            for(int j(0);j < (int)val[1].size();j++) cout << val[1][j].first << ' ';
        }*/

        for(int j(0);j < val[0].size() && Q;j++, Q--) cur += val[0][j].second, b[val[0][j].first] = char(i + '0');
        for(int j(0);j < val[1].size() && Q;j++, Q--) cur += val[1][j].second, b[val[1][j].first] = char(i + '0');

        if(cur < mn) 
        {
            mn = cur;
            ans = b;
        }else if(cur == mn) ans = min(ans, b);
    }

    cout << mn << '\n' << ans << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}