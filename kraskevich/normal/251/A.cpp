#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;


void openFiles() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int N = 100 * 1000;
long long x[N];


int main() {
    ios_base::sync_with_stdio(false);
    
    long long n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    
    long long res = 0;
    for (long long left = 0, right = 0; left < n; ++left) {
        while (right < n - 1 && x[right + 1] - x[left] <= d)
            ++right;
        if (right - left - 1 > 0)
            res += ((right - left) * (right - left - 1) / 2);
    }
    
    
    cout << res;
    
    
    
    return 0;
}