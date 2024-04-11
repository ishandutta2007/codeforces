
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int i = 0, cnt = 0, best = 0;
        while(i < n && s[i] == 'P') i++;
        for(; i < n; i++) {
            if(s[i] == 'A') {
                cnt = 0;
            }else {
                best = max(best, ++cnt);
            }
        }
        cout << best << endl;
    }
}