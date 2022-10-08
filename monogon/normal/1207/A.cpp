
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, f, b, p, h, c;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> b >> p >> f >> h >> c;
        int maxbeef = min(b / 2, p);
        int M = 0;
        for(int i = 0; i <= maxbeef; i++) {
            int chicken = min((b - 2 * i) / 2, f);
            M = max(M, h * i + c * chicken);
        }
        cout << M << endl;
    }
}