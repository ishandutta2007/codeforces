//
//  main.cpp
//  mushroomers
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

int n, k, t1, t2;

struct Tparty
{   
    int a, b, id, val;
    void scan(int ii)
    {
        id = ii;
        cin >> a >> b;
        val = max( a * t1 * k + b * t2 * 100, b * t1 * k + a * t2 * 100 );
    }
    void print()
    {
        cout << id + 1 << " " << val / 100 << "."; if (val % 100 < 10) cout << "0"; cout << val % 100 << endl;
    }
};

bool cmp(Tparty p1, Tparty p2)
{
    if (p1.val > p2.val) return true;
    if (p1.val == p2.val && p1.id < p2.id) return true;
    return false;
}

Tparty pp[1111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> t1 >> t2 >> k;
    k = 100 - k;
    for (int i = 0; i < n; i++) pp[i].scan( i );
    sort( pp, pp + n, cmp );
    for (int i = 0; i < n; i++) pp[i].print();
    return 0;
}