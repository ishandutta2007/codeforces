
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, k, a[N];
int b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 2; i < n; i++) {
            b[i] = (a[i] > a[i - 1] && a[i] > a[i + 1]) + b[i - 1];
        }
        int l = 1, best = -1;
        for(int i = 1; i + k - 1 <= n; i++) {
            int num = b[i + k - 2] - b[i];
            if(num > best) {
                best = num;
                l = i;
            }
        }
        cout << best + 1 << " " << l << '\n';
    }
}