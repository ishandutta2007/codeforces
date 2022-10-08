
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
        if(n == 1) {
            cout << "-1\n";
        }else {
            cout << 2;
            for(int i = 0; i < n - 1; i++) {
                cout << 3;
            }
            cout << "\n";
        }
    }
}