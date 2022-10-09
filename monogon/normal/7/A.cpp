
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s[8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 8; i++) {
        cin >> s[i];
    }
    int m = (1 << 8);
    int best = 16;
    for(int mask = 0; mask < m; mask++) {
        for(int mask2 = 0; mask2 < m; mask2++) {
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if((s[i][j] == 'B' && ((mask >> i) & 1) == 0 && ((mask2 >> j) & 1) == 0) ||
                        (s[i][j] == 'W' && (((mask >> i) & 1) == 1 || ((mask2 >> j) & 1) == 1))) {
                        goto endloop;
                    }
                }
            }
            best = min(best, __builtin_popcount(mask) + __builtin_popcount(mask2));
            endloop:;
        }
    }
    cout << best << endl;
}