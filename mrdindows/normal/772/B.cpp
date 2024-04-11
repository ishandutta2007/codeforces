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
#include <cmath>

using namespace std;


const int MAX_N = 1024;


struct Point {
    double x, y;
};


double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double vec(const Point& a, const Point& b, const Point& c) {
    return (a.x - b.x) * (a.y + b.y) + (b.x - c.x) * (b.y + c.y) + (c.x - a.x) * (c.y + a.y);
}

int n;

Point a[MAX_N * 3];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i + n] = a[i];
    }
    a[n * 2 + 1] = a[1], a[n * 2 + 2] = a[2];
    double ans = 1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j < i + n - 1; j++) {
            ans = min(ans, dist(a[i], a[j]) / 2.0);
            double s = abs(vec(a[i], a[j], a[j + 1]));
            double h = s / dist(a[i], a[j + 1]);
            ans = min(ans, h / 2.0);
        }
    }
    cout << fixed;
    cout.precision(15);
    cout << ans << '\n';
    return 0;
}