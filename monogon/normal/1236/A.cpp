
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// maximize 3(x + y)
// x (1, 2, 0) + y (0, 1, 2) <= (a, b, c)
// x <= a
// 2y <= c
// 2x + y <= b

int t;
int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int best = 0;
        for(int x = 0; x <= a; x++) {
            for(int y = 0; 2 * y <= c; y++) {
                if(2 * x + y <= b) {
                    best = max(best, 3 * (x + y));
                }
            }
        }
        cout << best << endl;
    }
}