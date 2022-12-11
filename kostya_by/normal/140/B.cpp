//
//  main.cpp
//  round100task2
//
//  Created by Sokol Kostya's MacBook on 04.01.11.
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

typedef unsigned long long ull;
#define mp make_pair

const long double eps = 1e-7;
const long long inf = 1e18;

using namespace std;

vector<int> a[300], alex;
int n;

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int aa;
            cin >> aa;
            aa--;
            a[i].push_back(aa);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int aa;
        cin >> aa;
        aa--;
        alex.push_back(aa);
    }
    for (int i = 0; i < n; i++)
    {
        int res = 100500, pos = 100500;
        for (int j = 0; j < n; j++)
        {
            int now = -1, pen;
            for (int k = 0; k < n; k++)
            {
                if (alex[k] <= j && alex[k] != i)
                {
                    now = alex[k];
                    break;
                }
            }
            if (now == -1) continue;
            for (int k = 0; k < n; k++) if (now == a[i][k]) pen = k;
           // cout << i << " " << j << " " << now << " " << pen <<  endl;
            if (pen < res)
            {
                res = pen;
                pos = j;
            }
        }
        cout << pos + 1 << " ";
    }
    return 0;
}