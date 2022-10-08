
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
string n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll msb = n[0] - '0';
        ll dig = n.length();
        ll ans = msb + (dig - 1) * 9;
        for(int i = 0; i < dig; i++) {
            if(n[i] - '0' < msb) {
                ans--;
                break;
            }else if(n[i] - '0' > msb) {
                break;
            }
        }
        cout << ans << endl;
    }
}