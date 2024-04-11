#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int k;
    
    cin >> k;
    
    int a[12];
    
    for(int i = 0; i < 12; ++i)
            cin >> a[i];
    
    sort(a, a + 12);
    
    int res = 0, i = 11;
    
    while(i >= 0 && k > 0) {
            ++res;
            k -= a[i];
            --i;
    }
    if(k > 0) 
         cout << -1;
    else
        cout << res;
    
    cin >> k;
    return 0;
}