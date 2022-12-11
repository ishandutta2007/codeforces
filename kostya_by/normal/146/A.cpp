//
//  main.cpp
//  luckyA
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
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

string st;
int sum, n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> st;
    n /= 2;
    for (int i = 0; i < n; i++)
    {
        int num = st[i] - '0';
        if (num != 4 && num != 7)
        {
            cout << "NO";
            return 0;
        }
        sum += num;
    }
    for (int i = n; i < 2 * n; i++)
    {
        int num = st[i] - '0';
        if (num != 4 && num != 7)
        {
            cout << "NO";
            return 0;
        }
        sum -= num;
    }
    if (sum == 0) cout << "YES"; else cout << "NO";
    return 0;
}