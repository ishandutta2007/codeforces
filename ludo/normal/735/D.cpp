#include<iostream>
//#include <bits/stdc++.h>

using namespace std;

bool isprime(int n)
{
    for (int div = 2; div * div <= n; div++) {
        if (n % div == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    bool prime = isprime(n);
    int ans;
    if (prime) {
        ans = 1;
    } else if (n % 2 == 0) {
        ans = 2;
    } else if (n > 3 && isprime(n - 2)) {
    	ans = 2;
    } else {
        ans = 3;
    }

    cout << ans << endl;

    return 0;
}