// Skyqwqa'a
#include <bits/stdc++.h>

char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

#define pb emplace_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5;

int tag[N << 2], mx[N << 2], cnt[N << 2], n, b[N], len[N << 2];
LL a[N];

#define ls (p << 1)
#define rs (p << 1 | 1)

void inline pushup(int p) {
    mx[p] = max(mx[ls], mx[rs]);
    cnt[p] = 0;
    if (mx[p] == mx[ls]) cnt[p] += cnt[ls];
    if (mx[p] == mx[rs]) cnt[p] += cnt[rs];
}

void inline add(int p, int k) {
    tag[p] += k, mx[p] += k;
}

void inline pushdown(int p) {
    if (tag[p]) {
        add(ls, tag[p]), add(rs, tag[p]);
        tag[p] = 0;
    }
}

void build(int p, int l, int r) {
    len[p] = r - l + 1;
    tag[p] = 0;
    if(l == r) { 
        mx[p] = 0, cnt[p] = 1;
        return; 
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void change(int p, int l, int r, int x, int y, int k) {
    if(x <= l && r <= y) {
        add(p, k);
        return ;
    }
    int mid = (l + r) >> 1;
    pushdown(p);
    if(x <= mid) change(p << 1, l, mid, x, y, k);
    if(mid + 1 <= y) change(p << 1 | 1, mid + 1, r, x, y, k);
    pushup(p);
}

LL ans;

int s1[N], t1, s2[N], t2;


struct E{
    int i, l, r, v;
};

vector<E> T[60];

void inline work(int w) {
    for (int i = 1, j = 0; i <= n; i++) {
        while (j < T[w].size() && T[w][j].i == i)
            change(1, 1, n, T[w][j].l, T[w][j].r, T[w][j].v), j++;
        if (mx[1] == 2) ans += cnt[1];
    }
    memset(tag, 0, sizeof tag);
    memcpy(cnt, len, sizeof len);
    memset(mx, 0, sizeof mx);
}

int inline get(LL x) {
    int c = 0;
    while (x) x -= x & -x, c++;
    return c;
}
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), b[i] = get(a[i]);
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int L = i;
        while (t1 && a[s1[t1]] >= a[i]) {
            //if (b[s1[t1]] != b[i]) {
                T[b[s1[t1]]].pb((E) { i, s1[t1 - 1] + 1, s1[t1], -1 });
                chkMin(L, s1[t1 - 1] + 1);
           // }
            
            t1--;
        }
        T[b[i]].pb((E) { i, L, i, 1 });
        L = i;
        while (t2 && a[s2[t2]] <= a[i]) {
            //if (b[s2[t2]] != b[i]) {
                T[b[s2[t2]]].pb((E) { i, s2[t2 - 1] + 1, s2[t2], -1 });
                chkMin(L, s2[t2 - 1] + 1);
            //}
            t2--;
        }
        T[b[i]].pb((E) { i, L, i, 1 });
        s1[++t1] = i;
        s2[++t2] = i;
    }
    for (int i = 0; i < 60; i++) work(i);
    printf("%lld\n", ans); 
    return 0;
}