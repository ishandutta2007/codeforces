//
//  main.cpp
//  sale
//
//  Created by Sokol Kostya's MacBook on 22.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, const char * argv[])
{
    int a[200], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = min(a[i], 0);
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < m; i++) ans -= a[i];
    cout << ans;
    return 0;
}