//
//  main.cpp
//  policarp
//
//  Created by Sokol Kostya's MacBook on 21.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int ans[1111], n, m;
pair<int, int> mm[44];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        mm[i].first = a;
        mm[i].second = i + 1;
    }
    sort(mm, mm + m);
    for (int i = 0; i < m; i++)
    {
        int num = mm[i].first;
        int color = mm[i].second;
        for (int i = 1; i <= n; i += 2)
        {
            if (ans[i] != 0) continue;
            int i1 = i + 1, i2 = i - 1;
            if (i1 == n + 1) i1 = 1;
            if (i2 == 0) i2 = n;
            if (ans[i1] == color) continue;
            if (ans[i2] == color) continue;
            ans[i] = color;
            num--;
            if (num == 0) break;
        }
        for (int i = 2; i <= n; i += 2)
        {
            if (num == 0) break;
            if (ans[i] != 0) continue;
            int i1 = i + 1, i2 = i - 1;
            if (i1 == n + 1) i1 = 1;
            if (i2 == 0) i2 = n;
            if (ans[i1] == color) continue;
            if (ans[i2] == color) continue;
            ans[i] = color;
            num--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}