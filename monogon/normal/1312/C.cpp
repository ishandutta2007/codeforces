
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 35;
int t, n;
ll k, a[N];
int cnt[64];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        fill(cnt, cnt + 64, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; a[i] > 0; j++) {
                cnt[j] += a[i] % k;
                a[i] /= k;
            }
        }
        for(int i = 0; i < 64; i++) {
            if(cnt[i] > 1) {
                cout << "NO\n";
                goto endloop;
            }
        }
        cout << "YES\n";
        endloop:;
    }
}