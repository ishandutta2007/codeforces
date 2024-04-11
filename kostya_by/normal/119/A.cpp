//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
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
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int a, b, n;
    cin >> a >> b >> n;
    int i;
    for (i = 0;; i++)
    {
        int now;
        if (i % 2 == 0)
        {
            now = nod(n, a);
           // cout << a << " " << n << " " << now << endl;
            n -= now;
            //a += now;
        } else
        {
            now = nod(n, b);
           // cout << b << " " << n << " " << now << endl;
            n -= now;
            //b += now;
        }
        if (n == 0)
        {
            if (i % 2 == 0) cout << 0; else cout << 1;
            return 0;
        }
    }
    return 0;
}