#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    ll k = n/m;
    cout << (n%m)*((k+1)*k/2) + (m-n%m)*(k*(k-1)/2) << ' ' << (n-m+1)*(n-m)/2;
}