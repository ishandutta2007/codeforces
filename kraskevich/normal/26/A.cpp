#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
     for(int i = 2; i * i <= n; ++i)
             if(n % i == 0)
                  return false;
     return true;
}

int main() {
    int n, res = 0;
    
    cin >> n;
    
    for(int i = 4; i <= n; ++i) {
            int cur = 0;
            for(int j = 2; j <= i; ++j)
                    if(prime(j) && i % j == 0)
                                cur++;
             if(cur == 2)
                    ++res;
    }
    
    cout << res;
    
    cin >> n;
    
    return 0;
}