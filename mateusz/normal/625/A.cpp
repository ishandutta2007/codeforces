#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int main() {
    
    long long n, a, b, c;
    
    cin >> n >> a >> b >> c;
    
    if (b - c >= a) {
        cout << n / a << endl;
    } else {

        long long glasses = max(0LL, (n - b) / (b - c));
        n -= glasses * (b - c);
        while (n >= b) {
            glasses++;
            n -= (b - c);
        }
        if (a <= b) {
            cout << glasses + n / a << endl;
        } else {
            cout << glasses + n / b << endl;
        }
    }
    
    return 0;
}