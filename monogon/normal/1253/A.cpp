
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
int a[N], b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k = 0;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            cin >> b;
            a[i] = b - a[i];
            k = max(k, a[i]);
            if(a[i] < 0) {
                flag = false;
            }
        }
        int mink = n, maxk = -1;
        if(!flag) {
            cout << "NO" << endl;
            goto endloop;
        }
        for(int i = 0; i < n; i++) {
            if(a[i] != 0 && a[i] != k) {
                cout << "NO" << endl;
                goto endloop;
            }
            if(a[i] == k) {
                mink = min(mink, i);
                maxk = max(maxk, i);
            }
        }
        for(int i = mink; i <= maxk; i++) {
            if(a[i] != k) {
                cout << "NO" << endl;
                goto endloop;
            }
        }

        cout << "YES" << endl;
        endloop:;
    }
}