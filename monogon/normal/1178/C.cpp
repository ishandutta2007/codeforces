
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 998244353;
int w, h;

int main() {
    ios::sync_with_stdio(false);
    cin >> w >> h;
    ll ans = 1;
    for(int i = 0; i < w + h; i++) {
        ans = (ans * 2) % M;
    }
    cout << ans << endl;
}