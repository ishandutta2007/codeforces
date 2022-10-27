#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int const nax = 3e5 + 10;
int n, a[nax], x;

void solve () {
    scanf("%d %d", &n, &x);

    int ct = 0;
    ll sum = 0;

    vector<int> ls;

    for (int i = 1 ; i <= n;  ++ i) {
        scanf("%d", a + i);
        if (a[i] >= x) ++ ct, sum += a[i];
        else ls.push_back(a[i]);
    }

    sort(ls.begin(), ls.end());
    reverse(ls.begin(), ls.end());

    int ans = ct;

    ll b = 0;

    for (int i = 0 ; i < (int)ls.size(); ++ i) {
        b += ls[i];
        if (1LL * (ct + i + 1) * (x) <= sum + b) ans = max(ans, ct + i + 1);
    }

    printf("%d\n", ans);
}

int main () {
    int T;

    for (cin >> T  ; T -- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/