#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;
using ll = long long ;
int n, m;
ll b[nax];
vector<int> a[nax];

ll solve () {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%lld", b + i);

    map<vector<int> , ll> ss;

    for (int i = 1 ; i <= m;  ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[v].emplace_back(u);
    }


    ll all = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!a[i].empty()) {
        sort(a[i].begin(), a[i].end());
        ss[a[i]] += b[i];
        }
    }
    ll ans = 0;
    for (auto &it : ss) {
        all += it.second;
        ans = __gcd(ans, it.second);
    }
    return __gcd(ans, all);
}

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ; ) {
        printf("%lld\n", solve());
        for (int i = 1 ; i <= n ; ++ i)
            a[i].clear();
    }
}
/*
    Good Luck
        -Lucina
*/