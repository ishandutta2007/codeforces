//
//  main.cpp
//  UOI
//
//  Created by Roman Rubanenko on 01/04/17.
//  Copyright  2016 Roman Rubanenko. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <memory.h>
#include <unordered_map>
#include <cassert>
#include <set>
#include <deque>
#include <queue>

using namespace std;


int n, p;


const int MAX_N = 100333;

pair<int, int> a[MAX_N];


bool can(double t) {
    double p = ::p;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max((t * a[i].first - a[i].second) / p, 0.0);
    }
    return sum < t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }
    if (p >= sum) {
        cout << "-1\n";
        return 0;
    }
    double l = 0, r = 2e18;
    for (int iter = 0; iter < 124; iter++) {
        double c = (l + r) / 2.0;
        if (can(c)) {
            l = c;
        } else {
            r = c;
        }
    }
    cout << fixed;
    cout.precision(15);
    cout << l << '\n';
    return 0;
}