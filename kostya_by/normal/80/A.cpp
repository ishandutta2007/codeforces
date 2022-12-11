//
//  main.cpp
//  t1c69
//
//  Created by Sokol Kostya's MacBook on 18.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main (int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 2; i * i <= m; i++) if (m % i == 0) 
    {
        cout << "NO";
        return 0;
    }
    for (int i = n + 1; i < m; i++)
    {
        bool fl = false;
        for (int j = 2; j * j <= i; j++) if (i % j == 0) fl = true;
        if (fl == false)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}