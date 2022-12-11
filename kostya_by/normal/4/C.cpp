//
//  main.cpp
//  regsystem
//
//  Created by Sokol Kostya's MacBook on 25.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

struct Trecord {
    string s;
    int id, ans;
};

Trecord records[100000];

bool cmp1(Trecord r1, Trecord r2);
bool cmp2(Trecord r1, Trecord r2);

bool cmp1(Trecord r1, Trecord r2)
{
    if (r1.s < r2.s) return true;
    if (r1.s == r2.s && r1.id < r2.id) return true;
    return false;
}

bool cmp2(Trecord r1, Trecord r2)
{
    if (r1.id < r2.id) return true;
    return false;
}

int n;

char s[40];

int main (int argc, const char * argv[])
{
    cin >> n; gets(s);
    for (int i = 0; i < n; i++)
    {
        cin >> records[i].s;
        records[i].id = i;
        records[i].ans = 0;
    }
    sort(records, records + n, cmp1);
    records[0].ans = 0;
    for (int i = 1; i < n; i++)
    {
        //cout << records[i].s << endl;
        if (records[i].s == records[i - 1].s) records[i].ans = records[i - 1].ans + 1;
    }
    sort(records, records + n, cmp2);
    for (int i = 0; i < n; i++) if (records[i].ans == 0) printf("OK\n"); else cout << records[i].s << records[i].ans << endl;
}