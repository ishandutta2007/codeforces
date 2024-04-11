#include <iostream>
using namespace std;

bool lucky(int n) {
     while(n) {
              if(n % 10 != 4 && n % 10 != 7)
                   return false;
              n /= 10;
     }
     return true;
}

int main() {
    int n;
    
    cin >> n;
    
    for(int i = 4; i <= n; ++i)
            if(lucky(i) && n % i == 0) {
                        cout << "YES";
                        return 0;
            }
    cout << "NO";
    return 0;
}