#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
ll calc(ll x) {
    if(x <= 0) return 0;
    ll y = sqrt(x);
    while((y + 1) * (y + 1) <= x) y++;
    while(y * y > x) y--;
    return 3 * (y - 1) + (x - y * y) / y + 1;
}
void rmain() {
    ll l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << "\n";
}
int main() {
    // x * x x * x + x * 2
    // 2 * x + 1
    int t;
    for(cin >> t; t--; ) rmain();
    return 0;
}