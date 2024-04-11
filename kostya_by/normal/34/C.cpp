//
//  main.cpp
//  list
//
//  Created by Sokol Kostya's MacBook on 22.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int used[10010];

int main (int argc, const char * argv[])
{
    char st[1000000];
    int now = 0, mx = 0;
    scanf("%s", &st);
    for (int i = 0; i < strlen(st); i++)
    {
        if (st[i] == ',')
        {
            used[now] = 1;
            mx = max(mx, now);
            now = 0;
            continue;
        }
        now = now * 10 + st[i] - '0';
    }
    used[now] = 1;
    mx = max(mx, now);
    int h = 1, t = 1;
    bool fl = false;
    while (t <= mx)
    {
        while (used[h] == 0) ++h;
        t = h;
        while (used[t] == 1) ++t;
        --t;
        //cout << h << " " << t << endl;
       // cin >> now;
        if (!fl)
        {
            fl = true;
        } else printf(",");
        if (h == t) printf("%d",h); else printf("%d-%d",h,t);
        ++t;
        h = t;
    }
    return 0;
}