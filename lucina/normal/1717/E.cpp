#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int nax = 2e5 + 10;
int n;
int phi[nax];

int main() {
    cin >> n;
    iota(phi + 1, phi + 1 + n, 1);
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = i + i ; j <= n ; j += i) {
            phi[j] -= phi[i];
        }
    }
    int64_t ans = 0;
    
    for (int x = 1 ; x <= n - 2 ; ++ x) {
        for (int n_c = x + x ; n_c < n; n_c += x) {
            /**
            
            */      
            int64_t c = n - n_c;
            if (c > n - 2) continue;
            /**
             *  n - c = gcd(a, b) = a + b
                lcm(c, gcd(a, b))
                let gcd(a, b) = x
                n - c = n_c = a + b
                numbers of (a, b) | a + b = n_c
                and gcd(a, b) = x is phi()
                a/x + b/x = n_c / x
                u + v = n_c / x, gcd(u, v) = gcd(u, u + v) = gcd(u, n_c) = 1
                It's phi(n_c / x)
                
                c = 1, gcd(a, b) = 2,  n-c = 2
                a + b = 2, and gcd(a, b) = 1
                gcd(a, n-c) = 2, 
                lcm(c, gcd(a, b))
                c = 1, a = 1, b = 1 ? 
            */
    
            ans += lcm(c, x) * phi[(n - c) / x] % MOD; 
        }
    }
    
    cout << ans % MOD << '\n';
}