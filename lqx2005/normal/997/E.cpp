#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
using namespace std;
typedef long long i64;
const int N = 2e5 + 10;
struct Query {
    int id, r;
    Query() {id = r = 0; }
    Query(int ID, int R) {id = ID, r = R; }
};
vector<Query> q[N];
int n, Q, a[N];
int stk1[N], stk2[N], top1 = 0, top2 = 0;
int add[N << 1], mn[N << 1], cnt[N << 1], tag[N << 1];
i64 sum[N << 1], ans[N];
void upd(int p, int l, int r) {
    mn[p] = min(mn[lc], mn[rc]);
    if(mn[lc] == mn[rc]) cnt[p] = cnt[lc] + cnt[rc];
    else cnt[p] = mn[lc] < mn[rc] ? cnt[lc] : cnt[rc];
    return;
}

void pushd(int p, int l, int r) {
    add[lc] += add[p], add[rc] += add[p];
    mn[lc] += add[p], mn[rc] += add[p], add[p] = 0;
    if(mn[p] == mn[lc]) {
        sum[lc] += 1ll * cnt[lc] * tag[p], tag[lc] += tag[p];
    }
    if(mn[p] == mn[rc]) {
        sum[rc] += 1ll * cnt[rc] * tag[p], tag[rc] += tag[p];
    }
    tag[p] = 0;
    return;
}

void build(int p, int l, int r) {
    if(l == r) return mn[p] = l, cnt[p] = 1, void();
    build(lc, l, mid), build(rc, mid + 1, r);
    return upd(p, l, r);
}

void modify(int p, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        add[p] += v, mn[p] += v;
        return;
    }
    pushd(p, l, r);
    if(L <= mid) modify(lc, l, mid, L, R, v);
    if(R > mid) modify(rc, mid + 1, r, L, R, v);
    return upd(p, l, r);
}

i64 query(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) return sum[p];
    pushd(p, l, r);
    i64 res = 0;
    if(L <= mid) res += query(lc, l, mid, L, R);
    if(R > mid) res += query(rc, mid + 1, r, L, R);
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &Q);
    for(int i = 1, l, r; i <= Q; i++) {
        scanf("%d%d", &l, &r);
        q[r].push_back(Query(i, l));
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        while(top1 && a[stk1[top1]] >= a[i]) {
            modify(1, 1, n, stk1[top1 - 1] + 1, stk1[top1], a[stk1[top1]] - a[i]);
            top1--;
        }
        stk1[++top1] = i;
        while(top2 && a[stk2[top2]] <= a[i]) {
            modify(1, 1, n, stk2[top2 - 1] + 1, stk2[top2], a[i] - a[stk2[top2]]);
            top2--;
        }
        stk2[++top2] = i;
        if(mn[1] == i) tag[1]++, sum[1] += cnt[1];
        for(Query &a : q[i]) {
            int l = a.r, id = a.id;
            ans[id] = query(1, 1, n, l, i);
        }
    }
    for(int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
    return 0;
}