//
//  main.cpp
//  Thwarting Demonstrations
//
//  Created by Sokol Kostya's MacBook on 30.05.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e15;

using namespace std;

struct summator
{       
    int a[111111];
    summator()
    {
        clear();
    }
    void clear()
    {
        for (int i = 0; i < 111111; i++) a[i] = 0;
    }
    void modify(int x)
    {
        while (x < 111111)
        {
            a[x]++;
            x = 2 * x - (x & (x - 1));
        }
    }
    int fsum(int x)
    {
        int res = 0;
        while (x != 0)
        {
            res += a[x];
            x = x & (x - 1);
        }
        return res;
    }
};

long long k, pref[111111], ans = 0, num[111111], need;
pair<long long, int> pp[111111];
int a, n, res;
summator ss;

void find(int ll, int rr)
{
    if (ll > rr) return;
    int xx = (ll + rr) / 2;
    if (pp[ xx ].first <= need)
    {
        res = max(res, xx);
        find(xx + 1, rr);
        return;
    }
    find(ll, xx  - 1);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    srand( time(NULL) );
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        pref[i] = a;
        pref[i] += pref[i - 1];
        pp[i] = mp( pref[i], i );
    }
    sort( pp, pp + n + 1 );
    for (int i = 0; i <= n; i++)
    {
        num[ pp[i].second ] = i + 1;
    }
    //for (int i = 0; i <= n; i++) cout << num[i] << " "; cout << endl;
    long long ll = 0, rr = inf;
    while (ll <= rr)
    {
        long long xx = (ll + rr) / 2;
        long long x = xx - inf / 2, sum = 0;
        ss.clear();
        ss.modify( num[ 0 ] );
      //  cout << num[ 0 ] << " ! " << endl;
        for (int i = 1; i <= n; i++)
        {
            need = pref[i] - x;
            if ( pp[0].first > need ) 
            {
                ss.modify( num[i] );
                continue;
            }
            res = 0;
            find(1, n);
            res = pp[res].second;
            int cur = ss.fsum( num[res] );
            //cout << num[res] << " ? " << endl;
            //cout << i << " " << res << " " << num[res] << endl;
            sum += 1ll * cur;
            ss.modify( num[i] );
           // cout << num[i] << " ! " << endl;
        }
     //   cout << "**************" << endl;
     //   cout << x << " " << sum << endl;
     //   cout << "--------------" << endl;
        if (sum >= k)
        {
            ans = max(ans, xx);
            ll = xx + 1;
            continue;
        }
        rr = xx - 1;
    }
    cout << ans - inf / 2;
    return 0;
}