//
//  main.cpp
//  snake
//
//  Created by Sokol Kostya's MacBook on 20.09.11.
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

int di[4] = { 1, 0,-1, 0};
int dj[4] = { 0, 1, 0,-1};
int rev[ 4 ] = { 2, 3, 0, 1 };

int ff[ 15 ][ 15 ][ 263000 ], n, m, mask_start = 0, ll, cur[ 15 ][ 15 ], nn[ 10 ], pt = 1, hh = 1;
char st[ 33 ][ 33 ];
pair<int, int> pii[ 10 ], start, finish;

struct state
{
    pair<int, int> p;
    int mask;
    state(int a, int b, int c)
    {
        p = mp(a, b);
        mask = c;
    }
    state()
    {
        p = mp(-1, -1);
        mask = 0;
    }
    bool check()
    {
        int ii = p.first;
        int jj = p.second;
        int mm = mask;
        for ( int i = 0; i < ll - 1; i++ ) nn[i] = mm & 3, mm /= 4;
        int rr = hh++;
        for ( int i = ll - 2; i >= 0; i-- )
        {
            if ( cur[ii][jj] == rr ) return false;
            cur[ii][jj] = rr;
            ii += di[ nn[i] ];
            jj += dj[ nn[i] ];
        }
        if ( cur[ii][jj] == rr ) return false;
        cur[ii][jj] = rr;
        return true;
    }
    void mask_print(int m)
    {
        for ( int i = 0; i < ll - 1; i++ ) cout << (m & 3) << " ", m /= 4;
        cout << endl;
    }
    void print()
    {
        cout << p.first << " " << p.second << " " << mask << endl;
    }
};

queue< state > qq;

int main (int argc, const char * argv[])
{
    srand( 2391 );
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m); gets( st[0] );
    for ( int i = 0; i < n; i++ ) scanf("%s", st[i] );
    for ( int i = 1; i < 10; i++ ) pii[i] = mp(-1, -1);
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
        {
            int num = st[i][j] - '0';
            if ( num > 0 && num < 10 ) pii[ num ] = mp( i, j ), ll = max( ll, num );
            if ( st[i][j] == '@' ) finish = mp(i, j);
        }
    start = pii[1];
    for ( int i = 1; i < 9; i++ )
    {
        if ( pii[i + 1] == mp(-1, -1) ) break;
        mask_start *= 4;
        for ( int j = 0; j < 4; j++ )
        {
            int ii = pii[i].first  + di[j];
            int jj = pii[i].second + dj[j];
            //cout << ii << " " << jj << " " << pii[i + 1].first << " " << pii[i + 1].second << endl;
            if ( mp(ii, jj) == pii[i + 1] ) mask_start += j;
        }
    }
    
    for ( int i = 0; i < ll - 2; i++ ) pt *= 4;
    
    qq.push( state( start.first, start.second, mask_start ) );
    ff[ start.first ][ start.second ][ mask_start ] = 1;
    
    //cout << pt << endl;
    
    //state().mask_print(15);
    //state().mask_print(240);
    
    //cout << pt << endl;
    
    while ( qq.size() != 0 )
    {
        state cur = qq.front(); qq.pop();
        //cur.print();
        int num = ff[ cur.p.first ][ cur.p.second ][ cur.mask ];
        if ( cur.p == finish )
        {
            cout << num - 1 << endl;
            return 0;
        }
        
        int mask_new = cur.mask / 4;
        for ( int i = 0; i < 4; i++ )
        {
            
            int ii = cur.p.first + di[i];
            int jj = cur.p.second + dj[i];
            int mm = mask_new + rev[ i ] * pt;
            if ( ii == -1 || jj == -1 || ii == n || jj == m ) continue;
            if ( ff[ii][jj][mm] != 0 ) continue;
            if ( st[ii][jj] == '#' ) continue;
            if ( state( ii, jj, mm ).check() == false )
            {
                ff[ii][jj][mm] = -1111;
                continue;
            }
            //cout << ii << " " << jj << " " << mm << " " << rev[i] << endl;
            ff[ii][jj][mm] = num + 1;
            qq.push( state( ii, jj, mm ) );
        }
        
    }
    
    cout << -1;
    
    return 0;
}