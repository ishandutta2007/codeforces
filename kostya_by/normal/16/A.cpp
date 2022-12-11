//
//  main.cpp
//  flags
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

int n, m;
char st[333][333];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    gets( st[0] );
    for (int i = 0; i < n; i++)
        gets( st[i] );
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++) if (st[i][j] != st[i][j - 1])
        {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++) if (st[i - 1][j] == st[i][j])
        {
            //cout << i << " " << j << endl;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}