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
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m;
vector< pair< int, int > > v, p, _new;

int main (int argc, const char * argv[])
{
    scanf("%d%d", &n, &m); 
    for ( int i = 1; i <= m; i++ )
    {
        int x, y; scanf("%d%d", &x, &y);
        v.pb( mp( x, y ) );
    }
    sort( v.begin(), v.end() );
    p.pb( mp( 1, 1 ) );
    int xx = 0;
    for ( int l = 0; l < v.size(); )
    {
        int r = l;
        while ( r + 1 < v.size() && v[l].first == v[r + 1].first ) r++;
        int _xx = v[l].first;
        if ( xx + 1 < _xx )
        {
            _new.pb( mp( p[0].first, n ) );
            p = _new; 
            _new.clear();
        }
        int lst = 1;
        for ( int i = l; i <= r; i++ )
        {
            int cur = v[i].second;
            if ( cur == lst )
            {
                lst++;
                continue;
            }
            int ll = lst, rr = cur - 1;
            _new.pb( mp( ll, rr ) );
            lst = cur + 1; 
        }
        int cur = n + 1;
        if ( lst < cur )
        {
            int ll = lst, rr = cur - 1;
            _new.pb( mp( ll, rr ) );
        }
        //cout << _xx << ": \n";
        //for ( int i = 0; i < p.size(); i++ ) cout << p[i].first << " " << p[i].second << "\n";
        //cout << "------------------\n";
        //for ( int i = 0; i < _new.size(); i++ ) cout << _new[i].first << " " << _new[i].second << "\n";
        //----------INTERSECTION-----------
        vector< pair< int, int > > _p;
        for ( int i = 0; i < _new.size(); i++ )
        {
            int l = _new[i].first;
            int r = _new[i].second;
            int id = 0;
            if ( p.back().second < l ) continue;
            if ( p[0].second < l )
            {
                int ll = 1, rr = p.size() - 1, res = 0;
                while ( ll <= rr )
                {
                    int xx = (ll + rr) / 2;
                    if ( p[xx].second < l )
                    {
                        res = max( res, xx );
                        ll = xx + 1;
                    } else rr = xx - 1;
                }
                id = res + 1;
            }
            int _l = max( p[id].first, l );
            int _r = r;
            if ( _l <= _r ) _p.pb( mp( _l, _r ) );
        }
        //cout << "------------------\n";
        //for ( int i = 0; i < _p.size(); i++ ) cout << _p[i].first << " " << _p[i].second << "\n";
        //cout << "******************\n";
        p = _p;
        if ( p.size() == 0 ) break;
        //---------------------------------
        _new.clear();
        xx = _xx;
        l = r + 1;
    }
    if ( p.size() > 0 && xx < n ) p.back().second = n;
    if ( p.size() == 0 || p.back().second != n ) printf("-1\n"); else printf("%d\n", n + n - 2);
    return 0;
}

/*
        vector< pair< int, int > > e;
        for ( int i = 0; i < p.size(); i++ ) 
        {
            e.pb( mp( p[i].first, -1 ) );
            e.pb( mp( p[i].second, 1 ) );
        }
        for ( int i = 0; i < _new.size(); i++ ) 
        {
            e.pb( mp( _new[i].first, -2 ) );
            e.pb( mp( _new[i].second, 2 ) );
        }
        sort( e.begin(), e.end() );
        vector< pair< int, int > > _p;
        int cur_ll = -1;
        bool fl1 = false;
        bool fl2 = false;
        for ( int i = 0; i < e.size(); i++ )
        {
            if ( e[i].second == -1 ) fl1 = true;
            if ( e[i].second == -2 ) fl2 = true;
            if ( fl1 == true && fl2 == true && cur_ll != -1 ) cur_ll = e[i].first;
            if ( e[i].fi )
        }*/