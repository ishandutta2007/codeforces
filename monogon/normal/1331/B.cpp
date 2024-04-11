
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            cout << i << (n / i) << endl;
            return 0;
        }
    }
}