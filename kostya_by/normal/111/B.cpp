//
//  main.cpp
//  pete_and_divisors
//
//  Created by Sokol Kostya's MacBook on 18.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> divisors, xx;
int last[1000000];
bool used[1000000];
int n, x, y, left;

int main (int argc, const char * argv[])
{
    scanf("%d",&n);
    for (int i = 0; i < 1000000; i++) last[i] = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&x,&y);
        int left = i - y;
        divisors.clear();
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                divisors.push_back(j);
                divisors.push_back(x / j);
            }
        }
        sort(divisors.begin(), divisors.end());
        int ans = 0;
        for (int ii = 0; ii < divisors.size(); ii++)
        {
            if (used[divisors[ii]] == true) continue;
            used[divisors[ii]] = true;
            if (last[divisors[ii]] < left) ++ans;
            last[divisors[ii]] = i;
        }
        for (int ii = 0; ii < divisors.size(); ii++)
        {
            used[divisors[ii]] = false;
        }
        printf("%d\n", ans);
    }
    return 0;
}