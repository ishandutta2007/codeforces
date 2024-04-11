
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int q, n, k;
ll a[MAX_N];
int r[MAX_N];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> k;
        cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 1) {
                r[cnt++] = i + 1;
            }
        }
        if(cnt < k || (cnt - k) % 2 == 1) {
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
            r[k - 1] = n;
            for(int i = 0; i < k; i++) {
                cout << r[i] << " ";
            }
            cout << endl;
        }
    }
}