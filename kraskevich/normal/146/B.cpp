#include <iostream>
#include <vector>
using namespace std;

int mask(int n) {
    int res = 0, p_pow = 1;
    while(n) {
             int t = n % 10;
             if(t == 7 || t == 4) {
                  res += p_pow * t;
                  p_pow *= 10;
             }
             n /= 10;
    }
    return res;
} 
    

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int ans = a + 1;
    while(mask(ans) != b)
                    ++ans;
    
    cout << ans;
    
    cin >> a;
    
    return 0;
}