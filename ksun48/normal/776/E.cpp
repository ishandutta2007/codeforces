#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL phi(LL n){    
    LL result = n;   // Initialize result as n
 
    // Consider all prime factors of n and subtract their
    // multiples from result
    for (LL p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result 
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
 
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}
int main() {
	LL n, k;
	cin >> n >> k;
	k = (k+1)/2;
	for(int i = 0; i < k; i++){
		n = phi(n);
		if(n == 1) break;
	}
	cout << n % 1000000007 << endl;

}