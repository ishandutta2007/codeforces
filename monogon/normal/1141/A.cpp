
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    if(m % n != 0) {
        cout << "-1\n";
        return 0;
    }
    m /= n;
    int ans = 0;
    while(m % 2 == 0) {
        m /= 2;
        ans++;
    }
    while(m % 3 == 0) {
        m /= 3;
        ans++;
    }
    if(m > 1) {
        cout << "-1\n";
    }else {
        cout << ans << "\n";
    }
}