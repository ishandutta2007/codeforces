//
//  main.cpp
//  colored field
//
//  Created by Sokol Kostya's MacBook on 22.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m, k, t;

int getnum(int ii, int jj);

int getnum(int ii, int jj)
{
    return (ii - 1) * m + jj;
}

vector<int> bad;

int main (int argc, const char * argv[])
{
    cin >> n >> m >> k >> t;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        bad.push_back(getnum(a, b));
    }
    sort(bad.begin(), bad.end());
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int num = getnum(a, b), before = 0;
        bool fl = false;
        for (int j = 0; j < bad.size(); j++)
        {
            if (num == bad[j]) fl = true;
            if (num > bad[j]) ++before;
        }
        if (fl) 
        {
            cout << "Waste\n";
            continue;
        }
        num -= before;
        if (num % 3 == 0) cout << "Grapes\n";
        if (num % 3 == 1) cout << "Carrots\n";
        if (num % 3 == 2) cout << "Kiwis\n";
    }
    return 0;
}