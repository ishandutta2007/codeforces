#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int maxI = -1, minI = -1, res = 0;
    for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(maxI < 0 || a[maxI] < a[i])
                    maxI = i;
            if(minI < 0 || a[minI] >= a[i])
                     minI = i;
    }
    if(maxI > minI)
            --res;
    res += maxI;
    res += n - 1 - minI;
    cout << res;
    cin >> n;
    return 0;
}