//
//  main.cpp
//  taskC
//
//  Created by Sokol Kostya's MacBook on 09.03.11.
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
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int sqrtd[26][400], num[26][222222], n, k, h[26], nn;
string ss, s, ans;
char ch[2];
bool used[222222];

void erase(int place, int nn)
{
    for (int i = 0; i < 400; i++)
    {
        if (nn - sqrtd[place][i] > 0)
        {
            nn -= sqrtd[place][i];
            continue;
        }
        int l = i * 500 + 1, r = (i + 1) * 500;
        for (int j = l; j <= r; j++)
        {
            int id = num[place][j];
            if (used[id] == true) continue;
            --nn;
            if (nn == 0)
            {
                sqrtd[place][i]--;
                used[id] = true;
                return;
            }
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> k >> ss >> n;
    s = "";
    for (int i = 0; i < k; i++) s = s + ss;
    for (int i = 0; i < s.size(); i++)
    {
        int place = s[i] - 'a';
        num[ place ][ ++h[place] ] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        int ll = 1, rr = h[i];
        if (rr == 0) continue;
        for (int j = 0; j < 400; j++)
        {
            int l = j * 500 + 1, r = (j + 1) * 500;
            l = max(l, ll);
            r = min(r, rr);
            if (l <= r) sqrtd[i][j] = r - l + 1;
            //cout << i << " " << j << " " << sqrtd[i][j] << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nn); gets(ch);
        int place = ch[1] - 'a';
        erase(place, nn);
    }
    ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (used[i] == true) continue;
        char ch = s[i];
        putchar(ch);
    }
    
    return 0;
}