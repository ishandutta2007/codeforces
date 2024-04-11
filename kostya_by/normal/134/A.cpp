//
//  main.cpp
//  average
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

int n, a[222222], sum = 0;
vector<int> ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if ( (sum - a[i]) % (n - 1) != 0 ) continue;
        if ( (sum - a[i]) / (n - 1) != a[i] ) continue;
        ans.pb( i );
    }
    printf("%d\n", int( ans.size() ));
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
    return 0;
}