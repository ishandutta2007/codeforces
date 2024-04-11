#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    scanf("%d", &n);

    vec< ll > a(n), p(n);
    vec< ll > res(n);
    vec< ll > sum(n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        a[i] = x;
        if(i) sum[i] = sum[i - 1];
        sum[i] += a[i];
    }

    for(int i = 0;i < n;i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    set< pii > seg;
    set< pii > :: iterator fnd;
    set< pii > :: iterator prv;
    set< pii > :: iterator nxt;
    ll cur = 0;

    for(int i = n - 1;i >= 0;i--) {
        res[i] = cur;
        if(i == n - 1) {
            seg.insert({p[i], p[i]});
            cur = max(cur, a[p[i]]);
            continue;
        }
        fnd = seg.lower_bound({p[i], 0});
        if(fnd == seg.end()) {
            prv = fnd;
            prv--;
            if(prv->second + 1 == p[i]) {
                int ql, qr;
                tie(ql, qr) = *prv;
                seg.erase(prv);
                seg.insert({ql, p[i]});
                cur = max(cur, sum[p[i]] - (ql ? sum[ql - 1] : 0ll));
            }else {
                seg.insert({p[i], p[i]});
                cur = max(cur, a[p[i]]);
            }
        }else if(fnd == seg.begin()) {
            nxt = fnd;
            if(p[i] + 1 == nxt->first) {
                int ql, qr;
                tie(ql, qr) = *nxt;
                seg.erase(nxt);
                seg.insert({p[i], qr});
                cur = max(cur, sum[qr] - (p[i]?sum[p[i] - 1] : 0));
            }else {
                seg.insert({p[i], p[i]});
                cur = max(cur, a[p[i]]);
            }
        }else {
            nxt = fnd;
            prv = fnd;
            prv--;
            int l1, r1, l2, r2;
            tie(l1, r1) = *prv;
            tie(l2, r2) = *nxt;

            if(r1 + 1 == p[i] && p[i] + 1 == l2) {
                seg.erase(prv);
                seg.erase(nxt);
                seg.insert({l1, r2});
                cur = max(cur, sum[r2] - (l1?sum[l1 - 1] : 0));
            }else if(r1 + 1 == p[i]) {
                seg.erase(prv);
                seg.insert({l1, p[i]});
                cur = max(cur, sum[p[i]] - (l1?sum[l1 - 1] : 0));
            }else if(p[i] + 1 == l2) {
                seg.erase(nxt);
                seg.insert({p[i], r2});
                cur = max(cur, sum[r2] - (p[i]?sum[p[i] - 1] : 0));
            }else {
                seg.insert({p[i], p[i]});
                cur = max(cur, a[p[i]]);
            }
        }
    }

    for(int i = 0;i < n;i++) {
        printf("%I64d\n", res[i]);
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}