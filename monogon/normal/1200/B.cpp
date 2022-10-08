
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 105;
int q, n, m, k;
int h[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for(int i = 1; i < n; i++) {
            if(h[i - 1] >= h[i] - k) {
                m += h[i - 1] - max(h[i] - k, 0);
            }else {
                m -= (h[i] - k - h[i - 1]);
                if(m < 0) {
                    cout << "NO" << endl;
                    goto endloop;
                }
            }
        }
        cout << "YES" << endl;
        endloop:;
    }
}