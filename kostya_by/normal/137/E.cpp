//
//  main.cpp
//  last_chance
//
//  Created by Sokol Kostya's MacBook on 20.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

char st[200000];

int a[200000], sum[200000];

int minimator[1000000], fake;

int fmin(int xx);
void modify(int xx, int val);
int prev(int x);

int prev(int x)
{
    return x & (x - 1);
}

int fmin(int xx)
{
    int x = xx;
    x += 410000;
    int res = 1000000;
    while (x != 0)
    {
        res = min(res, minimator[x]);
        x = prev(x);
    }
    return res;
}

void modify(int xx, int val)
{
    int x = xx;
    x += 410000;
    while (x < 1000000)
    {
        minimator[x] = min(minimator[x], val);
        x = 2 * x - prev(x);
    }
}

int main (int argc, const char * argv[])
{
    for (int i = 0; i < 1000000; i++) minimator[i] = 1000000;
    gets(st);
    int n = int(strlen(st));
    for (int i = 0; i < n; i++)
    {
        a[i] = 2;
        if (st[i] == 'a' || st[i] == 'A') a[i] = -1;
        if (st[i] == 'e' || st[i] == 'E') a[i] = -1;
        if (st[i] == 'i' || st[i] == 'I') a[i] = -1;
        if (st[i] == 'o' || st[i] == 'O') a[i] = -1;
        if (st[i] == 'u' || st[i] == 'U') a[i] = -1;
    }
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
    int anslen = 0, ansnum = 0;
    for (int i = 0; i < n; i++)
    {
        int now = sum[i];
        int left = fmin(now);
        //cout << left << " " << now << endl;
        if (left == 1000000) 
        { 
            modify(now, i);
            continue;
        }
        if (i - left > anslen)
        {
            anslen = i - left;
            ansnum = 0;
        }
        if (i - left == anslen) ansnum++;
        modify(now, i);
    }
    for (int i = 0; i < n; i++)
    {
        //cout << sum[i] << " ";
        if (sum[i] < 0) continue;
        if (i + 1 > anslen)
        {
            anslen = i + 1;
            ansnum = 0;
        }
        if (i + 1 == anslen) ansnum++;
    }
    //cout << endl;
    if (anslen == 0) cout << "No solution"; else cout << anslen << " " << ansnum;
    return 0;
}