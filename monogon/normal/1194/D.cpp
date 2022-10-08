
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> k;
        if(k % 3 == 0) {
            n %= (k + 1);
            cout << (n == k ? "Alice" : n % 3 == 0 ? "Bob" : "Alice") << endl;
        }else {
            cout << (n % 3 == 0 ? "Bob" : "Alice") << endl;
        }
    }
}