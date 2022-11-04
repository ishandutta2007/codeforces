#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, s; cin >> n >> s;
    cout << (s / (n/2+1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}