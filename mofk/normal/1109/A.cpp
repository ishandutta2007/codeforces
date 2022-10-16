#include <bits/stdc++.h>

using namespace std;

int n;
int s[300005];
int odd[1<<20], even[1<<20];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i], s[i] ^= s[i-1];
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (i & 1) ans += odd[s[i]], ++odd[s[i]];
        else ans += even[s[i]], ++even[s[i]];
    }
    cout << ans << endl;
    return 0;
}