#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve(){
    cin >> n;

    int cnt = 0;
    for(int i=1;i<=n;i+=2) n -= i, cnt++;
    cout << cnt + !!n;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}