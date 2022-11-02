#include <iostream>
using namespace std;

const int maxN = 1000 * 50; 

int main() {
    int n, a, b;
    
    cin >> n >> a >> b;
    
    int res[n], sum[n], i = 1;
    res[0] = sum[0] = 1;
    
    if(n == 1 && (a || b)) {
         cout << -1;
         return 0;
    }
    
    if(n <= 2 && a && !b) {
         cout << -1;
         return 0;
    }
    
    if(!b && a) {
           sum[1] = 2; 
           res[1] = 1;
           ++i;
    }
    
    while(b) {
             res[i] = sum[i - 1] + 1;
             sum[i] = sum[i - 1] + res[i];
             ++i;
             --b;
             if(i >= n && b) {
                  cout << -1;
                  return 0;
             }
    }
    
    while(a) {
             res[i] = res[i - 1] + 1;
             ++i;
             --a;
              if(i >= n && a) {
                  cout << -1;
                  return 0;
             }
    }
    
    while(i < n) {
            res[i] = 1;
            ++i;
    }
    
    for(int j = 0; j < n; ++j)
            cout << res[j] << " ";
    
    cin >> n;
    
    return 0;
}