//
//  main.cpp
//  analiz_cf
//
//  Created by Sokol Kostya's MacBook on 19.11.11.
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

int mmm[ 13 ] = { 0, 31, 29, 31, 30, 31, 30 ,31 ,31, 30, 31, 30, 31 };
queue< int > q;
char st[ 5000005 ];
int n, m;

int ss( int id )
{
    return st[id] - '0';
}

int get_num()
{
    int mm = 10 * ss(5) + ss(6);
    int dd = 10 * ss(8) + ss(9);
    int res = 0;
    for ( int i = 0; i < mm; i++ ) res += 24 * mmm[i];
    res += 24 * (dd - 1);
    int hh = 10 * ss(11) + ss(12);
        mm = 10 * ss(14) + ss(15);
    int sss = 10 * ss(17) + ss(18);
    res += hh;
    res *= 60;
    res += mm;
    res *= 60;
    res += sss;
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m); gets( st );
    while ( gets( st ) != '\0' )
    {
        int cur = get_num();
        q.push( cur );
        while ( q.back() - q.front() >= n ) q.pop();
        if ( q.size() >= m )
        {
            for ( int i = 0; i <= 18; i++ ) cout << st[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}