//
//  code.cpp
//  JustForCoding
//
//  Created by Yevhen Zadorozhnii on 2/17/20.
//  Copyright  2020 Yevhen Zadorozhnii. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;
using ll = long long;

int a[1010010];
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int d;
        cin >> d;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0) {
                continue;
            }
            int s = min(d / i, a[i]);
            d -= s * i;
            a[0] += s;
        }
        cout << a[0] << endl;
    }
    
    return 0;
}