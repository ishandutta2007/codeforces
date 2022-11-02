#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int n, a[MAXN];
long long ans;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) {
        int t;
        for (t=0; i+(1<<t)<n; t++); t--;
        ans += a[i];
        a[i+(1<<t)] += a[i];
        cout << ans << '\n';
    }
    return 0;
}