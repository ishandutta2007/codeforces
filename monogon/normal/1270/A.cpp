
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, k1, k2, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k1 >> k2;
        int m = true;
        while(k1--) {
            cin >> a;
        }
        while(k2--) {
            cin >> a;
            if(a == n) m = false;
        }
        cout << (m ? "YES" : "NO") << endl;
    }
}