
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll dist1 = max(x - 1, y - 1);
    ll dist2 = max(n - x, n - y);
    cout << (dist1 <= dist2 ? "White\n" : "Black\n");
}