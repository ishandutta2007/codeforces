#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 1000100;

int n, ar[maxn], m;
int pre[maxn], bit[maxn];
int ans[maxn];

vector<pair<int, int> > v[maxn];

void upd(int i, int v) {
    for (i++; i < maxn; i += i & -i) bit[i] ^= v;
}

int qry(int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i) ret ^= bit[i];
    return ret;
}

map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
        pre[i + 1] = pre[i] ^ ar[i];
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        v[l - 1].push_back(MP(r, i));
    }

    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(ar[i])) upd(mp[ar[i]], ar[i]);
        mp[ar[i]] = i;
        upd(i, ar[i]);

        for (auto j : v[i]) {
            ans[j.B] = pre[j.A] ^ pre[i] ^ qry(j.A - 1);
            //cout << (pre[j.A] ^ pre[i]) << ' ' << qry(j.A - 1) << endl;
        }
    }

    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}