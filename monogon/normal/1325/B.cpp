
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
ll a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        set<ll> s;
        for(int i = 0; i < n; i++) {
            cin >> a;
            s.insert(a);
        }
        cout << s.size() << endl;
    }
}