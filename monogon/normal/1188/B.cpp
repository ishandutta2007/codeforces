
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
ll p, k, a;
multiset<ll> m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p >> k;
    for(int i = 0; i < n; i++) {
        cin >> a;
        ll a4 = (a * a) % p;
        a4 = (a4 * a4) % p;
        m.insert(((a4 - a * k) % p + p) % p);
    }
    ll c = 0;
    while(m.size()) {
        ll num = m.count(*m.begin());
        c += num * (num - 1) / 2;
        m.erase(*m.begin());
    }
    cout << c << endl;
}