#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int INF = 2e9;
const int mod = 1e9 + 7;
const ll LONGINF = 4e18;

ll a[100100], sb[100100];



void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%I64d", &a[i]);
    sb[0] = 0;
    for(int i = 1; i < n; ++i){
        sb[i] = sb[i - 1] + (i % 2 ? 1 : -1) * abs(a[i - 1] - a[i]);
    }
    ll mn[2] = {LONGINF, LONGINF}, mx[2] = {-LONGINF, -LONGINF};
    ll ans = -LONGINF;
    for(int i = 0; i < n; ++i) {
        mn[i % 2] = min(mn[i % 2], sb[i]);
        mx[i % 2] = max(mx[i % 2], sb[i]);
        if(i % 2 == 0)
            ans = max(ans, -sb[i] + mx[(i & 1) ^ 1]);
        else
            ans = max(ans, sb[i] - mn[(i & 1) ^ 1]);
    }
    printf("%I64d\n", ans);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//    freopen("J.in", "r", stdin);

    solve();

    return 0;
}