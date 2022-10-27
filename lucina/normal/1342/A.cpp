#include<bits/stdc++.h>
using namespace std;

void solve () {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    if (x > y) swap(x, y);

    long long ans1 = 0, ans2 = 0;

    ans1 += 1LL * x * b;
    ans1 += 1LL * a * (y - x);

    ans2 = 1LL * (x + y) * a;


    printf("%lld\n", min(ans1, ans2));
}

int main () {
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}