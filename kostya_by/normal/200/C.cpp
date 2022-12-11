//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 24.06.11.
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

int h = 1;
map< string, int > num;

struct team
{
    string name;
    int id, pts, gs, gd, gp;
    void print()
    {
        cout << name << " " << pts << " " << gs << " " << gd << endl;
    }
};

vector<int> tt;
team teams[5];
int x = -1, y = -1;

bool cmp1(team t1, team t2)
{
    if ( t1.id < t2.id ) return true;
    return false;
}

bool cmp2(team t1, team t2)
{
    if ( t1.pts > t2.pts ) return true;
    if ( t1.pts == t2.pts && t1.gs - t1.gd > t2.gs - t2.gd ) return true;
    if ( t1.pts == t2.pts && t1.gs - t1.gd == t2.gs - t2.gd && t1.gs > t2.gs ) return true;
    if ( t1.pts == t2.pts && t1.gs - t1.gd == t2.gs - t2.gd && t1.gs == t2.gs && t1.name < t2.name ) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < 5; i++)
    {
        string name1, name2;
        int a, b, id1, id2;
        cin >> name1 >> name2;
        scanf("%d:%d", &a, &b);
        if ( num[ name1 ] == 0 )
        {
            teams[ h ].name = name1;
            teams[ h ].id = h;
            num[ name1 ] = h++;
        }
        if ( num[ name2 ] == 0 )
        {
            teams[ h ].name = name2;
            teams[ h ].id = h;
            num[ name2 ] = h++;
        }
        id1 = num[ name1 ];
        id2 = num[ name2 ];
        if (a > b)
        {
            teams[ id1 ].pts += 3;
        }
        if (a == b)
        {
            teams[ id1 ].pts++;
            teams[ id2 ].pts++;
        }
        if (a < b)
        {
            teams[ id2 ].pts += 3;
        }
        teams[ id1 ].gs += a; teams[ id1 ].gd += b;
        teams[ id2 ].gs += b; teams[ id2 ].gd += a;
        teams[ id1 ].gp++; teams[ id2 ].gp++;
    }
    
    for (int i = 1; i <= 4; i++) if (teams[i].gp == 2) tt.pb( i );
    
    if (teams[ tt[0] ].name != "BERLAND") swap( tt[0], tt[1] );
    
    teams[ tt[0] ].gp = teams[ tt[1] ].gp = 3;
    teams[ tt[0] ].pts += 3;
    
    for (int a = 1; a < 500; a++)
        for (int b = 0; b < a; b++)
        {
            teams[ tt[0] ].gs += a; teams[ tt[0] ].gd += b;
            teams[ tt[1] ].gs += b; teams[ tt[1] ].gd += a;
            sort( teams + 1, teams + 4 + 1, cmp2 );
            if ( teams[ 1 ].name == "BERLAND" || teams[ 2 ].name == "BERLAND" )
            {
                if ( x == -1 ) x = a, y = b;
                if ( x - y > a - b ) x = a, y = b;
                if ( x - y == a - b && y > b ) x = a, y = b;
            }
            sort( teams + 1, teams + 4 + 1, cmp1 );
            teams[ tt[0] ].gs -= a; teams[ tt[0] ].gd -= b;
            teams[ tt[1] ].gs -= b; teams[ tt[1] ].gd -= a;
        }
    if (x == -1) cout << "IMPOSSIBLE"; else cout << x << ":" << y;
    return 0;
}