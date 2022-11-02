#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string  a,b;
    cin >> a >> b;

    set<pair<char,char>> c;

    for(int i = 0; i < n; i++) {
        if( a[i] > b[i] ) { 
            cout << -1 << '\n';
            return;
        }
        if( a[i] != b[i] )
            c.insert({a[i], b[i]});
    }

    int ans = 0;

    while( c.size() ) {
        auto x = *c.begin();
        c.erase(c.begin()); 
        ans++;

        for (char ch = x.second; ch <= 't'; ch++)
           if( c.count({x.first, ch}) ) { 
               c.erase({x.first, ch});
               c.insert({x.second, ch});
           }
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}