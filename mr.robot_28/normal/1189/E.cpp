#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int mod;
 
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
 
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
 
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
 
int pw4(int x) {
    return mult(mult(x, x), mult(x, x));
}
 
int n, p, k;
map < int, int > mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> mod >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int val = sub(pw4(x), mult(k, x));
        ans += mp[val];
        mp[val]++;
    }
    cout << ans;
    return 0;
}