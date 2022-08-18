//
//  main.cpp
//  Contests
//
//  Created by Roman Rubanenko on 3/5/17.
//  Copyright  2017 Roman Rubanenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAX_VALUE = 10001;

long long cnt[MAX_VALUE];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    long long ans = 0;
    for (int x = 0; x < MAX_VALUE; x++) {
        for (int y = 0; y < x; y++) {
            if (__builtin_popcount(x ^ y) == k) {
                ans += cnt[x] * cnt[y];
            }
        }
        if (k == 0) {
            ans += cnt[x] * (cnt[x] - 1) / 2;
        }
    }
    cout << ans << '\n';
    return 0;
}