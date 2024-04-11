#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int bit[N];

void update(int pos, int val, int lim) {
    for(; pos <= lim; pos += pos & -pos) {
        bit[pos] += val;
    }
}

int query(int pos) {
    int sum = 0;
    for (; pos > 0; pos -= pos & -pos) sum += bit[pos];
    return sum;
}


ll qs[N];
vector<ll> tab;

int get_index(ll val) {
    return lower_bound(tab.begin(), tab.end(), val) - tab.begin() + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    bool ok = true, sorted = true;
    ll ma = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &qs[i]);
        sorted &= (qs[i] >= 0);
        qs[i] += qs[i -1];
        ok &= (qs[i] >= 0);
        tab.push_back(qs[i]);
        ma = max(ma, qs[i]);
    }
    if (!ok || qs[n] != ma) {
        return !printf("-1");
    }
    if (sorted) {
        return !printf("0");
    }
    sort(tab.begin(), tab.end());
    tab.resize(unique(tab.begin(), tab.end()) - tab.begin());
    ll ans = 0;
    for (int i = 1; i <= n;i ++) {
        int id = get_index(qs[i]);
        ans += i - 1 - query(id);
        update(id, 1, tab.size());
    }
    printf("%lld", ans);

}