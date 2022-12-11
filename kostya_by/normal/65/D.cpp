//
//  main.cpp
//  sorting hat
//
//  Created by Sokol Kostya's MacBook on 03.05.11.
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

struct Tstate
{
    int a, b, c, d;
    Tstate()
    {
        a = b = c = d = 0;
    }
    Tstate(int aa, int bb, int cc, int dd)
    {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
    }
    int val()
    {
        return a + b + c + d;
    }
    int mn()
    {
        return min( min(a, b), min(c, d) );
    }
};

class cmp
{
public:
    bool operator()(Tstate s1, Tstate s2)
    {
        if (s1.a < s2.a) return true;
        if (s1.a == s2.a && s1.b < s2.b) return true;
        if (s1.a == s2.a && s1.b == s2.b && s1.c < s2.c) return true;
        if (s1.a == s2.a && s1.b == s2.b && s1.c == s2.c && s1.d < s2.d) return true;
        return false;
    }
};

set< Tstate, cmp > sst;
char st[11111];
int val[555], n;
bool ok[4];

void dfs(Tstate state)
{
    if (sst.find( state ) != sst.end()) return;
    sst.insert( state );
    int ii = state.val();
    if (ii == n)
    {
        if ( state.a == state.mn() ) ok[0] = true;
        if ( state.b == state.mn() ) ok[1] = true;
        if ( state.c == state.mn() ) ok[2] = true;
        if ( state.d == state.mn() ) ok[3] = true;
        return;
    }
    if ( st[ii] != '?' )
    {
        Tstate next = state;
        if (st[ii] == 'G') ++next.a;
        if (st[ii] == 'S') ++next.b;
        if (st[ii] == 'H') ++next.c;
        if (st[ii] == 'R') ++next.d;
        dfs( next );
        return;
    }
    Tstate next = state;
    if ( state.a == state.mn() )
    {
        next.a++;
        dfs( next );
        next.a--;
    }
    if ( state.b == state.mn() )
    {
        next.b++;
        dfs( next );
        next.b--;
    }
    if ( state.c == state.mn() )
    {
        next.c++;
        dfs( next );
        next.c--;
    }
    if ( state.d == state.mn() )
    {
        next.d++;
        dfs( next );
        next.d--;
    }
    return;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n; gets(st); gets(st);
    val['G'] = 0;
    val['S'] = 1;
    val['H'] = 2;
    val['R'] = 3;
    Tstate start(0, 0, 0, 0);
    dfs( start );
    if (ok[0]) cout << "Gryffindor" << endl;
    if (ok[2]) cout << "Hufflepuff" << endl;
    if (ok[3]) cout << "Ravenclaw" << endl;
    if (ok[1]) cout << "Slytherin" << endl;
    return 0;
}