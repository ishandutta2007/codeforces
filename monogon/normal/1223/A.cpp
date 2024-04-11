
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        cout << (n < 3 ? 4 - n : n % 2) << endl;
    }
}