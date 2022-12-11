//
//  main.cpp
//  almost primes
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

int resh[3333], n;

int main (int argc, const char * argv[])
{
    for (int i = 2; i < 3333; i++)
    {
        if (resh[i] == 0)
        {
            int j = i;
            while (j < 3333) 
            {
                resh[j]++;
                j += i;
            }
        }
    }
    int ans = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) ans += (resh[i] == 2);
    cout << ans;
    return 0;
}