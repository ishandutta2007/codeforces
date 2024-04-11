
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll m, n;
int dig[10], sum[10];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> m;
        dig[1] = m % 10;
        sum[1] = dig[1];
        for(int i = 2; i < 10; i++) {
            dig[i] = (dig[i - 1] + m) % 10;
            sum[i] = sum[i - 1] + dig[i];
        }
        cout << sum[9] * ((n / m) / 10) + sum[(n / m) % 10] << endl;
    }
}