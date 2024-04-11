//
//  main.cpp
//  cheaterius
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

int n, ans = 0;
bool used[11111];
char ss[2];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n; gets( ss );
    for (int i = 0; i < n; i++)
    {
        gets( ss );
        int a = ss[0] - '0';
        int b = ss[1] - '0';
        gets( ss );
        int c = ss[1] - '0';
        int d = ss[0] - '0';
        if (i != n - 1) gets( ss );
        int abcd = a * 1000 + b * 100 + c * 10 + d;
        int bcda = b * 1000 + c * 100 + d * 10 + a;
        int cdab = c * 1000 + d * 100 + a * 10 + b;
        int dabc = d * 1000 + a * 100 + b * 10 + c;
        bool ok = used[abcd] | used[bcda] | used[cdab] | used[dabc];
        if (ok == true) continue;
        used[abcd] = true;
        ++ans;
    }
    cout << ans;
    return 0;
}