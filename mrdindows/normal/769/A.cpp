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

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    cout << a[n / 2] << '\n';
    return 0;
}