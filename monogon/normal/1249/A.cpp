
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int q, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for(int i = 0; i < n - 1; i++) {
            if(a[i] == a[i + 1] - 1) {
                cout << 2 << endl;
                goto endloop;
            }
        }
        cout << 1 << endl;
        endloop:;
    }
}