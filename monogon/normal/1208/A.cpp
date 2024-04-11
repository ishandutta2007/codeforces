
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int T;
ll a, b, n;

// a, b, a + b, a, b

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> a >> b >> n;
        cout << (n % 3 == 0 ? a : n % 3 == 1 ? b : (a ^ b)) << endl;
    }
}