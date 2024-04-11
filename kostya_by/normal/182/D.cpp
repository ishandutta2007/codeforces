//
//  main.cpp
//  common divisors
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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

char s1[111111], s2[111111];
int n, m, ans;
bool ff[111111], f1[100001][660], f2[100001][660], gg[111111];
vector<int> d1, d2;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s1 ); gets( s2 );
    n = strlen( s1 ); m = strlen( s2 );
    ff[0] = true;
    for (int i = 0; i < min( n, m ); i++)
    {
        if (s1[i] != s2[i]) ff[i + 1] = false; else ff[i + 1] = ff[i];
    }
    for (int i = 1; i <= n; i++) if (n % i == 0) d1.pb( i );
    for (int j = 1; j <= m; j++) if (m % j == 0) d2.pb( j );
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < d1.size(); j++)
        {
            if (i <= d1[j]) 
            {
                f1[i][j] = true;
                continue;
            }
            if ( s1[ i - 1 ] != s1[ i - 1 - d1[j] ] ) f1[i][j] = false; else f1[i][j] = f1[i - d1[j]];
        }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < d2.size(); j++)
        {
            if (i <= d2[j]) 
            {
                f2[i][j] = true;
                continue;
            }
            if ( s2[ i - 1 ] != s2[ i - 1 - d2[j] ] ) f2[i][j] = false; else f2[i][j] = f2[i - d2[j]];
        }
    for (int i = 0; i < d1.size(); i++)
    {
        bool fl = true;
        for (int j = 1; j <= n; j++) if (f1[j][i] == false) fl = false;
      //  if (fl == true) cout << d1[i] << endl;
        gg[ d1[i] ] = fl;
    }
  //  cout << "-----" << endl;
    for (int i = 0; i < d2.size(); i++)
    {
        bool fl = true;
        for (int j = 1; j <= m; j++) if (f2[j][i] == false) fl = false;
        if ( (ff[ d2[i] ] & gg[ d2[i] ] & fl) == true ) ++ans;
    }
    cout << ans;
    return 0;
}