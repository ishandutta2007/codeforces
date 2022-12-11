//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 24.09.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int a[111][111], n, m;
int rr[ 111 ], cc[ 111 ];

int main (int argc, const char * argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    bool fl = true;
    for (;fl == true;)
    {
        fl = false;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < m; j++) sum += a[i][j];
            if (sum < 0)
            {
                fl = true;
                rr[ i + 1 ] ^= 1;
                for (int j = 0; j < m; j++) a[i][j] = -a[i][j]; 
            }
        }
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += a[i][j];
            if (sum < 0)
            {
                fl = true;
                cc[ j + 1 ] ^= 1;
                for (int i = 0; i < n; i++) a[i][j] = -a[i][j];
            }
        }
    }
    int nn = 0;
    for ( int i = 1; i <= n; i++ ) if ( rr[i] == 1 ) nn++;
    cout << nn << " ";
    for ( int i = 1; i <= n; i++ ) if ( rr[i] == 1 ) cout << i << " "; cout << endl;
    
    nn = 0;
    for ( int i = 1; i <= m; i++ ) if ( cc[i] == 1 ) nn++;
    cout << nn << " ";
    for ( int i = 1; i <= m; i++ ) if ( cc[i] == 1 ) cout << i << " "; cout << endl;
    return 0;
}