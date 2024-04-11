
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll k = n * (n + 1) / 2;
    cout << (k % 2 == 0 ? 0 : 1) << endl;
}