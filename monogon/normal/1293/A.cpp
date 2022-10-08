
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n, s, k, a;
set<ll> r;

bool check(ll x) {
    return x >= 1 && x <= n && r.count(x) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s >> k;
        r.clear();
        for(int i = 0; i < k; i++) {
            cin >> a;
            r.insert(a);
        }
        for(int i = 0; ; i++) {
            if(check(s - i) || check(s + i)) {
                cout << i << endl;
                break;
            }
        }
    }
}