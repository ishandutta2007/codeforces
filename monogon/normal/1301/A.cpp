
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string a, b, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        n = a.length();
        for(int i = 0; i < n; i++) {
            if(a[i] != c[i] && b[i] != c[i]) {
                cout << "NO" << endl;
                goto endloop;
            }
        }
        cout << "YES" << endl;
        endloop:;
    }
}