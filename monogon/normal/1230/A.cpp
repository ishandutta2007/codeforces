
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int a[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int sum = a[0] + a[1] + a[2] + a[3];
    for(int i = 0; i < 8; i++) {
        int val = 0;
        for(int j = 0; j < 3; j++) {
            if((i >> j) & 1) {
                val += a[j];
            }
        }
        if(2 * val == sum) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}