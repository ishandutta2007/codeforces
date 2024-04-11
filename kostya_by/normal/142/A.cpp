//
//  main.cpp
//  round102task1
//
//  Created by Sokol Kostya's MacBook on 12.01.11.
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

long long n, ans1, ans2;

int main (int argc, const char * argv[])
{
    cin >> n;
    ans1 = ans2 = -1;
    for (long long aa = 1; aa * aa * aa <= n; aa++)
    {
        for (long long bb = 1; aa * bb * bb <= n; bb++)
        {
            long long cc = n;
            if (cc % aa != 0) continue;
            cc /= aa;
            if (bb <= 0) continue;
            if (cc % bb != 0) continue;
            cc /= bb;
           // if (cc < bb) break;
            long long val1 = (aa + 1) * (bb + 2) * (cc + 2);
            long long val2 = (cc + 1) * (bb + 2) * (aa + 2);
            long long val3 = (bb + 1) * (cc + 2) * (aa + 2);
            if (ans1 == -1) ans1 = ans2 = val1;
            ans1 = min(ans1, min(val1, min(val3, val2)));
            ans2 = max(ans2, max(val1, max(val3, val2)));
            //cout << aa + 1 << " " << bb + 2 << " " << cc + 2 << " " << val << endl;
        }
    }
    cout << ans1 - n << " " << ans2 - n;
    return 0;
}