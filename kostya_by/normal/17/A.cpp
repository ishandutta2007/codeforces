//
//  main.cpp
//  noldbach
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

vector<int> prime;
bool resh[1111], used[11111];
int n, k;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 2; i * i < 1111; i++)
    {
        if (resh[i] == true) continue;
        int j = i * i;
        while (j < 1111)
        {
            resh[j] = true;
            j += i;
        }
    }
    cin >> n >> k;
    for (int i = 2; i < 1111; i++) if (resh[i] == false) prime.pb( i );
    for (int i = 0; i < prime.size() - 1; i++) used[ prime[i] + prime[i + 1] + 1 ] = true;
   // cout << n << " " << k << endl;
    for (int i = 2; i <= n; i++) if (resh[i] == false && used[i] == true) --k;
    if (k <= 0) cout << "YES"; else cout << "NO";
    return 0;
}