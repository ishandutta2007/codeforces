//
//  main.cpp
//  petya_and_square
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

pair<int, int> pp[4], cur;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, x, y;
    cin >> n >> cur.first >> cur.second;
    n /= 2;
    pp[0].first = n; pp[0].second = n;
    pp[1].first = n + 1; pp[1].second = n;
    pp[2].first = n; pp[2].second = n + 1;
    pp[3].first = n + 1; pp[3].second = n + 1;
    for (int i = 0; i < 4; i++)
    {
        if (pp[i] == cur)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}