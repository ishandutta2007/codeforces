#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, h;
    
    cin >> n >> m >> h;
    
    --n, --h;
    
    int a[m], sum = 0, total = 0;
    
    for(int i = 0; i < m; ++i) {
            cin >> a[i];
            if(i == h)
                 --a[i];
            if(i != h)
                 sum += a[i];
            total += a[i];
    }
    if(sum < n && sum + a[h] >= n) {
           cout << 1;
           return 0;
    }
    if(sum + a[h] < n) {
           cout << -1;  
           return 0;
    }
    double p = 1;
    
    for(int i = 0; i < n; ++i) {
            p *= (double)sum / (double)total;
            --sum;
            --total;
    }
    
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << 1 - p;
    
    cin >> n;
    return 0;      
}