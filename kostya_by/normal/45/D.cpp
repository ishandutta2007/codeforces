//
//  main.cpp
//  dates
//
//  Created by Sokol Kostya's MacBook on 22.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tperiod
{
    int l, r, id;
};

bool cmp(Tperiod p1, Tperiod p2);
bool cmp1(Tperiod p1, Tperiod p2);
bool add(int v);

bool cmp(Tperiod p1, Tperiod p2)
{
    if (p1.r - p1.l < p2.l - p2.r) return true;
    if ((p1.r - p1.l) == (p2.l - p2.r) && p1.l < p2.l) return true;
    if ((p1.r - p1.l) == (p2.l - p2.r) && p1.l == p2.l && p1.r < p2.r) return true;
    return false;
}

bool cmp1(Tperiod p1, Tperiod p2)
{
    if (p1.id < p2.id) return true;
    return false;
}

Tperiod periods[101];

bool used[100000010], u[101];

int ans[101];
int p1[101], p2[1000001];

bool add(int v)
{
    u[v] = true;
    for (int i = periods[v].l; i <= periods[v].r; i++)
    {
        if (p2[i] == 0)
        {
            p2[i] = v;
            p1[v] = i;
            u[v] = false;
            return true;
        }
        if (u[p2[i]] == true) continue;
        if (add(p2[i]))
        {
            p2[i] = v;
            p1[v] = i;
            u[v] = false;
            return true;
        }
    }
    u[v] = false;
    return false;
}

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    { 
        cin >> periods[i].l >> periods[i].r;
        periods[i].id = i;
    }
    sort(periods, periods + n, cmp);
    for (int i = 0; i < n; i++)
    {
        //cout << i << " " << periods[i].l << " " << periods[i].r << endl;
        for (int j = periods[i].l; j <= periods[i].r; j++)
        {
            if (used[j] == false) 
            {
                ans[periods[i].id] = j;
                used[j] = true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0) 
        {
            p1[i] = ans[i];
            p2[ans[i]] = i;
        }
    }
    sort(periods, periods + n, cmp1);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            add(i);
        }
    }
    for (int i = 1; i <= n; i++) cout << p1[i] << " ";
    return 0;
}