
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int T, n;
ll a, b;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> n >> a >> b >> s;
        int first = n, last = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                first = min(first, i);
                last = max(last, i);
            }
        }
        ll cost = a * n + b * (n + 1);
        if(first > last) {
            cout << cost << endl;
            continue;
        }
        cost += 2 * a + b * (last - first + 2);
        
        int prev = first;
        for(int i = first; i <= last; i++) {
            if(s[i] == '1' && s[prev] == '0') {
                cost += min(2 * a - b * (i - prev - 1), (ll) 0);
            }
            if(s[i] == '1' || s[prev] == '1') {
                prev = i;
            }
        }
        cout << cost << endl;
    }
}