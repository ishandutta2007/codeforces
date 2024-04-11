
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;

int main() {
    cin >> n;
    int m = n;
    while(m < 1004) {
        int sum = 0;
        n = m;
        while(n > 0) {
            sum += (n % 10);
            sum %= 4;
            n /= 10;
        }
        if(sum == 0) {
            cout << m << endl;
            return 0;
        }
        m++;
    }
}