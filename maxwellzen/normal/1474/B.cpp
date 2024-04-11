#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int d;
        cin >> d;
        vector<bool> sieve(20+3*d, true);
        for (int i = 2; i < 20+3*d; i++) {
            if (sieve[i]) {
                for (int m = i*i; m < 20+3*d; m+=i) {
                    sieve[m]=false;
                }
            }
        }
        long long start = 1+d;
        while (! sieve[start]) {
            start++;
        }
        long long second = start+d;
        while (!sieve[second]) second++;
        cout << min(start*start*start, start*second) << endl;
    }
    return 0;
}