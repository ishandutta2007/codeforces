
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int q, n;
int a[N], pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        fill(pre + 1, pre + n + 1, -1);
        int m = n + 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(pre[a[i]] != -1) {
                m = min(m, i - pre[a[i]]);
            }
            pre[a[i]] = i;
        }
        cout << (m == n + 1 ? -1 : m + 1) << endl;
    }
}