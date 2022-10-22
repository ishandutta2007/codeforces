#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
void solve() {
    string s2;
    cin >> s2;
    int cnt = 0;
    for(int i = 0; i < sz(s2); i++) {
        if(s2[i] == 'A') cnt++;
        else cnt--;
        if(cnt < 0) {
            cout << "NO\n";
            return;
        }
    }
    if(s2.back() == 'A') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}