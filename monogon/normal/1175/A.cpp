
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll q, n, k;

int main() {
    cin >> q;
    while(q--) {
        cin >> n >> k;
        ll moves = 0;
        while(n != 0) {
            if(n % k == 0) {
                n /= k;
                moves++;
            }else {
                moves += (n % k);
                n -= n % k;
            }
        }
        cout << moves << endl;
    }
}