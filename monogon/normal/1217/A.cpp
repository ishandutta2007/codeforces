
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll s, i, e, T;

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> s >> i >> e;
        if(s + e <= i) {
            cout << 0 << endl;
            continue;
        }else if(s > i + e) {
            cout << (e + 1) << endl;
            continue;
        }
        // maximum points for strength: e
        // minimum points for strength: k such that
        // 0 <= k <= e
        // s + k > i + (e - k)
        // 2k > i + e - s
        // k = floor((i + e - s) / 2) + 1
        cout << (e - min(e, 1 + (i + e - s) / 2) + 1) << endl;
    }
}