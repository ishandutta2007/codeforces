//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 22.06.11.
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
const long long inf = 1e18;

using namespace std;

set< pair<int,int> > ans;
queue< int > qq;
int n, p;
long long r, x, y;

struct Tgun
{
    long long dist, rr;
    int m, p;
    void scan()
    {
        long long xx, yy;
        scanf("%I64d%I64d%d%d%I64d", &xx, &yy, &m, &p, &rr);
        rr *= rr;
        dist = (xx - x) * (xx - x) + (yy - y) * (yy - y);
       // cout << xx << " " << yy << " " << m << " " << p << " " << rr << endl;
    }
    void print()
    {
        cout << dist << " " << rr << " " << m << " " << p << endl;
    }
};


bool sm[333333];
Tgun gun[333333];

struct tv
{
    int x, y, lson, rson;
    vector<int> id;
    tv()
    {
        x = y = lson = rson = 0;
        id.clear();
    }
};

struct sss
{
    vector< pair<int, int> > e;
    void add(int x, int id)
    {
        e.pb( mp(x, id) );
    }
    void bsort()
    {
        sort( e.begin(), e.end(), greater< pair<int, int> >() );
    }
    void under(int x)
    {
        while ( e.size() != 0 )
        {
            pair<int, int> cur = e.back();
            if (cur.first > x) break;
            e.pop_back();
            qq.push( cur.second );
        }
    }
};

bool cmp( Tgun g1, Tgun g2 )
{
    if (g1.dist < g2.dist) return true; return false;
}

struct fenwick
{
    sss tt[333333];
    void add(int pos, int val, int id)
    {
        while (pos < 333333)
        {
            tt[pos].add( val, id );
            pos = 2 * pos - (pos & (pos - 1));
        }
    }
    void make(int pos, int x)
    {
        while (pos != 0)
        {
            tt[pos].under( x );
            pos = pos & (pos - 1);
        }
    }
    void ss()
    {
        for (int i = 0; i < 333333; i++) tt[i].bsort();
    }
};

fenwick ff;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> x >> y >> gun[0].p >> gun[0].rr >> n;
    for (int i = 1; i <= n; i++) gun[i].scan();
    sort( gun + 1, gun + n + 1, cmp );
   // for (int i = 1; i <= n; i++) gun[i].print();
    for (int i = 1; i <= n; i++) ff.add( i, gun[i].m, i );
    ff.ss();
    gun[0].rr *= gun[0].rr;
    qq.push( 0 );
    while (qq.size() != 0)
    {
        int ii = qq.front();
        qq.pop();
        if (sm[ ii ] == true) continue;
        sm[ ii ] = true;
        long long r = gun[ ii ].rr;
        int mm = gun[ ii ].p;
        int ll = 1, rr = n, xx = 1;
        if ( r < gun[1].dist ) continue;
        //cout << ii << endl;
        while (true)
        {
            if (ll > rr) break;
            int x = (ll + rr) / 2;
            //cout << ll << " " << x << " " << rr << endl; 
            if (gun[x].dist <= r)
            {
                xx = max(x, xx);
                ll = x + 1;
            } else rr = x - 1;
        }
       // cout << r << " " << xx << endl;
        ff.make( xx, mm );
    }
    int ans = 0;
    for (int i = 1; i < 333333; i++) ans += sm[i];
    cout << ans;
    return 0;
}