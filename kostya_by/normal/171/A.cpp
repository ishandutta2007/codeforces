//
//  main.cpp
//  secret_nums
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

int rev(int x)
{
    vector<int> cur;
    while (x > 0)
    {
        cur.pb( x % 10 );
        x /= 10;
    }
    int res = 0;
    if (cur.size() == 0) return 0;
    for (int i = 0; i < cur.size(); i++) 
    {
        res *= 10;
        res += cur[i];
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b;
    cin >> a >> b;
    cout << a + rev( b );
    return 0;
}