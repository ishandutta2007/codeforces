#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 0;
    long long ans = 0;
    for(long long i = 1, rem = 0; i <= n + 1; i++){
        long long use = (rem + k - 1) / k;
        ans += use;
        rem += a[i];
        rem = max(0LL, rem - 1LL* use * k);
    }
    cout << ans;
}