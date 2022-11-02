#include <iostream>
using namespace std;

int main() {
    long long n, d, m, l;
    
    cin >> n >> d >> m >> l;
    
    long long res = -1, curX = 0;
    
    for(int i = 0; i < n; ++i) {
            long long left = i * m, right = left + l;
            if(curX + d < left || curX > right + d) {
                    break;
                    res = curX + d;
            }
            long long jumps = (right - curX) / d;
            curX += d * jumps;
    }
    
    if(res < 0)
           res = curX + d;
    
    cout << res;
    
    cin >> n;
    
    return 0;
}