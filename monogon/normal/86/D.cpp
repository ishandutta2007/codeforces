
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct query {
    int l, r, idx;
};

const int N = 2e5 + 5, M = 1e6 + 5, K = 450;
int n, t, l, r;
int a[N], s[M];
ll ans, v[N];
query q[N];

inline bool cmp(const query &a, const query &b) {
    if(a.l / K != b.l / K) return a.l < b.l;
    return a.r < b.r;
}
inline void push(int x) {
    s[x]++;
    ans += 1LL * x * (2 * s[x] - 1);
}
inline void pop(int x) {
    ans -= 1LL * x * (2 * s[x] - 1);
    s[x]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < t; i++) {
        cin >> l >> r;
        l--; r--;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, q + t, cmp);
    l = 0, r = -1;
    for(int i = 0; i < t; i++) {
        while(r < q[i].r) push(a[++r]);
        while(l > q[i].l) push(a[--l]);
        while(r > q[i].r) pop(a[r--]);
        while(l < q[i].l) pop(a[l++]);
        v[q[i].idx] = ans;
    }
    for(int i = 0; i < t; i++) {
        cout << v[i] << endl;
    }
}