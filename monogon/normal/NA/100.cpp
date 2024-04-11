
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int m = 1;
        int L = (1 << 8);
        for(int i = 1; i < L; i++) {
            int A = 0, B = 0, C = 0;
            for(int j = 0; j < 8; j++) {
                if((i >> j) & 1) {
                    if(j & 1) A++;
                    if((j >> 1) & 1) B++;
                    if((j >> 2) & 1) C++;
                }
            }
            if(A <= a && B <= b && C <= c) {
                m = max(m, __builtin_popcount(i));
            }
        }
        cout << m - 1 << endl;
    }
}