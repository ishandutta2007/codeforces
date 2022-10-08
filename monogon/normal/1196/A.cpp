
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        cout << (a + b + c) / 2 << endl;
    }
}