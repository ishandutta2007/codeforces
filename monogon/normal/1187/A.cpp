
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll n, s, t;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        cout << max(n - s + 1, n - t + 1) << endl;
    }
}