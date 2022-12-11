//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
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

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

double sqr(double x)
{
    return x * x;
}

int a[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 774, 777, 747};
int used[500];

int main (int argc, const char * argv[])
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 = s1 + s2;
    for (int i = 0; i < s1.size(); i++) used[s1[i]]++;
    for (int i = 0; i < s3.size(); i++) used[s3[i]]--;
    for (int i = 0; i < 500; i++) if (used[i] != 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}