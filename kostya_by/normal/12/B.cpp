//
//  main.cpp
//  check_solution
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

int n;
string m, res = "";
vector<int> dd;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    if (n == 0)
    {
        if (m == "0") cout << "OK"; else cout << "WRONG_ANSWER";
        return 0;
    }
    while (n != 0)
    {
        dd.pb( n % 10 );
        n /= 10;
    }
    sort( dd.begin(), dd.end() );
    while ( dd.front() == 0 ) next_permutation(dd.begin(), dd.end());
    for (int i = 0; i < dd.size(); i++)
    {
        char c = dd[i] + '0';
        res = res + c;
    }
    if (res == m) cout << "OK"; else cout << "WRONG_ANSWER";
    return 0;
}