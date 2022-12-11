//
//  main.cpp
//  taskB_round_2_krok
//
//  Created by Sokol Kostya's MacBook on 20.04.11.
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
const long long mod = 1000000007;

using namespace std;

string start, finish;
int k, n;
int f[2][1111], sum = 0;
int num = 0;

int main (int argc, const char * argv[])
{
    cin >> start >> finish >> k;
    f[0][0] = 1;
    n = start.size();
    sum = 1;
    for (int i = 1; i <= k; i++) 
    {
        for (int j = 0; j < n; j++) f[1][j] = (sum - f[0][j] + mod) % mod;
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            f[0][j] = f[1][j];
            sum += f[1][j];
            sum %= mod;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int nn = f[0][i];
        for (int j = 0; j < n; j++) if ( start[ (i + j) % n ] != finish[ j ] ) nn = 0;
        num += nn;
        num %= mod;
    }

    cout << num;
    
    return 0;
}