//
//  main.cpp
//  animals
//
//  Created by Sokol Kostya's MacBook on 22.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[200];

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int now;
        cin >> now;
        a[i] = now * (n - i);
        sum += a[i];
    }
    sort(a, a + n);
    int ans = 0;
    if (sum <= x) ans = n; else
    {
        for (int i = 0; x - a[i] >= 0; i++)
        {
            ++ans;
            x -= a[i];
        }
    }
    cout << ans;
    return 0;
}