//
//  main.cpp
//  vasilisa help
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

int d1, d2, c1, c2, r1, r2;

bool check(int a, int b, int c, int d)
{
    if (a + b != r1) return false;
    if (c + d != r2) return false;
    if (a + c != c1) return false;
    if (b + d != c2) return false;
    if (a + d != d1) return false;
    if (b + c != d2) return false;
    return true;
}

int main (int argc, const char * argv[])
{
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for (int a = 1; a < 10; a++)
        for (int b = 1; b < 10; b++)
            for (int c = 1; c < 10; c++)
                for (int d = 1; d < 10; d++)
                {
                    if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
                    if (check(a, b, c, d) == true)
                    {
                        cout << a << " " << b << endl << c << " " << d << endl;
                        return 0;
                    }
                }
    cout << -1;
    return 0;
}