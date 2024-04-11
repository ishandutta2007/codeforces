//
//  main.cpp
//  taskC
//
//  Created by Sokol Kostya's MacBook on 04.03.11.
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

vector<int> divisors;
int a[22222], n, ans = -1000000000, ff[22222][500];

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) if (n % i == 0 && i * 2 != n) divisors.pb( i );
   // for (int i = 0; i < divisors.size(); i++) cout << divisors[i] << " "; cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < divisors.size(); j++)
        {
            int prev = i - divisors[j];
            if (prev >= 0) ff[i][j] = ff[prev][j];
            ff[i][j] += a[i];
        }
    }
    for (int i = 0; i < divisors.size(); i++)
    {
        int ii = divisors[i];
        for (int j = 0; j < ii; j++)
        {
            int now = ff[ (j - ii + n + n) % n ][i];
            //cout << j << " " << ii << " " << now << endl;
            ans = max(ans, now);
        }
    }
    cout << ans;
    return 0;
}