//
//  main.cpp
//  t1c69
//
//  Created by Sokol Kostya's MacBook on 18.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

string names[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};

bool graf[7][7];
int z[7], n, a, b, c;

long long ans1 = 1000000000000, ans2 = 0;

void rec(int pos);

void rec(int pos)
{
    if (pos == n)
    {
        int mx = 0, mn = 2000000000, num = 0;
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                if (graf[i][j] && z[i] == z[j]) ++num;
        int aa = 0, bb = 0, cc = 0;
        for (int i = 0; i < 7; i++)
        {
            if (z[i] == 0) ++aa;
            if (z[i] == 1) ++bb;
            if (z[i] == 2) ++cc;
        }
        if (aa * bb * cc == 0) return;
        mx = max(a / aa, max(b / bb, c / cc));
        mn = min(a / aa, min(b / bb, c / cc));
        if (mx - mn < ans1 || (mx - mn == ans1 && num > ans2))
        {
            //for (int i = 0; i < 7; i++) cout << z[i] << " ";
            //cout << endl;
            ans1 = mx - mn;
            ans2 = num;
        }
    }
    if (pos < n)
    {
        for (int k = 0; k < 3; k++)
        {
            z[pos] = k;
            rec(pos + 1);
        }
    }
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name1, name2;
        cin >> name1 >> name2 >> name2;
        int ii, jj;
        for (int j = 0; j < 7; j++) if (names[j] == name1) ii = j;
        for (int j = 0; j < 7; j++) if (names[j] == name2) jj = j;
        graf[ii][jj] = true;
    }
    cin >> a >> b >> c;
    n = 7;
    rec(0);
    cout << ans1 << " " << ans2;
    return 0;
}