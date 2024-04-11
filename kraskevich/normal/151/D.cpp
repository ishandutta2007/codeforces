#include <iostream>
using namespace std;

const long long base = 1000000007;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    if(n == 1) {
         cout << m;
         cin >> n;
         return 0;
    }
    if(k == n) {
         long long res = 1;
         for(int i = 0; i < (n + 1) / 2; ++i)
                 res = (res * m) % base;
         cout << res % base;
         cin >> n;
         return  0;
    }
    if(k == 1 || k > n) {
         long long res = 1;
         for(int i = 0; i < n; ++i)
                 res = (res * m) % base;
         cout << res % base;
         cin >> n;
         return 0;
    }
    if(k % 2 == 0) {
         cout << m % base;
         cin >> n;
         return 0;
    }
    if(k % 2 == 1) {
         long long res = m * m;
         cout << res % base;
         cin >> n;
         return 0;
    }
}