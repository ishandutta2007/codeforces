#include <bits/stdc++.h>

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

void solve() {
    vector<ll> v;
    ll n, t;
    cin >> t;
    n = t;
    for(ll i = 2; i * i <= n; ++i) {
        while(n % i == 0)
            v.push_back(i), n /= i;
    }
    if(n > 1)
        v.push_back(n);
    if(v.size() < 2) {
        puts("1");
        puts("0");
        return;
    }
    if(v.size() == 2) {
        puts("2");
        return;
    }
    printf("1\n%I64d\n", v[0] * v[1]);
}

int main() {
    solve();
    return 0;
}