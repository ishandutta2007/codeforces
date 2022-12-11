//
//  main.cpp
//  razvedka
//
//  Created by Sokol Kostya's MacBook on 22.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main (int argc, const char * argv[])
{
    int a[200], n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = a[1];
    int ans = 1;
    for (int i = 2; i <= n; i++) 
        if (fabs(a[i] - a[i + 1]) < fabs(a[ans] - a[ans + 1])) ans = i;
    cout << ans << " ";
    if (ans == n) ans = 0;
    cout << ans + 1;
    return 0;
}