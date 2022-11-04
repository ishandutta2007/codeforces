#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b;

void solve(){
    cin >> a >> b;

    if(!a && !b){
        cout << 0;
        return;
    }

    if(a == b){
        cout << 1;
        return;
    }

    if(abs(a - b) % 2){
        cout << -1;
        return;
    }

    cout << 2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}