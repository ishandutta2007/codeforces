//
//  code.cpp
//  JustForCoding
//
//  Created by Yevhen Zadorozhnii on 2/17/20.
//  Copyright  2020 Yevhen Zadorozhnii. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

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
        sort(a, a + n);
        if (count(a, a + n, d) == 1) {
            cout << 1 << endl;
            continue;
        }
        int res = d / a[n - 1];
        if (d % a[n - 1]) {
            ++res;
            if (res == 1) {
                ++res;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}