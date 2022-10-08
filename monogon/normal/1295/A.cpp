
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        if(n % 2 == 1) {
            cout << 7;
            n -= 3;
        }
        while(n > 0) {
            cout << 1;
            n -= 2;
        }
        cout << endl;
    }
}