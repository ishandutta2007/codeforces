
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 5e5 + 5;
const int SQRT_N = 710;
int q, t, x, y;
// table[i][j] = sum of indices i (mod j)
ll table[SQRT_N][SQRT_N];
ll a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> t >> x >> y;
        if(t == 1) {
            a[x] += y;
            for(int i = 1; i < SQRT_N; i++) {
                table[x % i][i] += y;
            }
        }else {
            if(x < SQRT_N) {
                cout << table[(y + x) % x][x] << endl;
            }else {
                y = (y + x) % x;
                ll tot = 0;
                while(y < MAX_N) {
                    tot += a[y];
                    y += x;
                }
                cout << tot << endl;
            }
        }
    }
}