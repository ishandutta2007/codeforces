
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2005;
int n;
ll m;
ll a[N], b[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b + n);
    ll bestx = 2e9;
    for(int i = 0; i < n; i++) {
        ll x = ((b[i] - a[0]) % m + m) % m;
        for(int j = 0; j < n; j++) {
            c[j] = (a[j] + x) % m;
        }
        sort(c, c + n);
        for(int j = 0; j < n; j++) {
            if(c[j] != b[j]) goto endloop;
        }
        bestx = min(bestx, x);
        endloop:;
    }
    cout << bestx << endl;
}