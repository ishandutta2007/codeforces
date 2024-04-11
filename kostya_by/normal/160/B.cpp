//
//  main.cpp
//  unlucky
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

vector<int> aa, bb;
string st;
int n;
bool up = true, down = true;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> st;
    for (int i = 0; i < n; i++) aa.pb( st[i] - '0' );
    for (int i = n; i < 2 * n; i++) bb.pb( st[i] - '0' );
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    for (int i = 0; i < n; i++)
    {
        if (aa[i] <= bb[i]) up = false;
        if (aa[i] >= bb[i]) down = false;
    }
    if (up || down) cout << "YES"; else cout << "NO";
    return 0;
}