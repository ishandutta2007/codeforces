#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int x; cin >> x;
    cout << (x+1)/10;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}