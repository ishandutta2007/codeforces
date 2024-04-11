
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s, best, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        best = s;
        int bestk = 1;
        for(int k = 2; k <= n; k++) {
            s2 = s.substr(0, k - 1);
            if((k + n) % 2 == 0) reverse(s2.begin(), s2.end());
            s2 = s.substr(k - 1, n - k + 1) + s2;
            if(s2 < best) {
                best = s2;
                bestk = k;
            }
        }
        cout << best << endl << bestk << endl;
    }
}