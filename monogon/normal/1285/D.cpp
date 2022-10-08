
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
ll a[N];

ll ans(int l, int r) {
    if(l >= r || a[r] == 0) return 0;
    ll x = (1LL << (int) log2(a[r]));
    int i = l;
    while(a[i] < x) i++;
    for(int j = i; j <= r; j++) a[j] -= x;
    if(i == l) return ans(l, r);
    else return x + min(ans(l, i - 1), ans(i, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << ans(0, n - 1) << endl;
}