
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll a, b, k, h[N], w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> k;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        ll mod = h[i] % (a + b);
        if(mod == 0) mod = a + b;
        w[i] = -1 + (mod + a - 1) / a;
    }
    sort(w, w + n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(w[i] <= k) {
            k -= w[i];
            sum++;
        }else break;
    }
    cout << sum << endl;
}