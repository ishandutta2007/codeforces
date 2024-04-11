#include<bits/stdc++.h>
using namespace std;
const int nax = 128;
int n;
char s[nax];

void solve() {
    cin >> n >> s;
    int ans = 0;
    for (int i = 0 ; i + 1 < n ; ++ i)
        if (s[i] == s[i + 1] && s[i] == '0')
            ans += 2;
        
    for (int i = 0 ; i + 2 < n ; ++ i) 
        if (s[i] == s[i + 2] && s[i + 1] == '1' && s[i] == '0')
            ans += 1;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    
    for (cin >> T ; T -- ;) {
        solve();
    }
}