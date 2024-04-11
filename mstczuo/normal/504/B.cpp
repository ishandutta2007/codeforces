# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

const int MAXN = 210000;

struct tree {
    int a[MAXN];
    int n;
    void init(int _n) {
        this->n = _n;
        memset(a, 0, sizeof(a));
    }
    int get(int x) {
        int ans = 0;
        for( ; x > 0; x -= x & (-x)) ans += a[x];
        return ans;
    }
    void set(int x) {
        for( ; x <= n; x += x & (-x)) a[x] += 1;
    }
}tr;

int a[MAXN];
int ra[MAXN];
int rb[MAXN];
int rc[MAXN];
int c[MAXN];

int getAns(int o) {
    int L = -1, R = tr.n, Mid;
    int tmp; o += 1;
    while(R - L > 1) {
        Mid = (L + R) >> 1;
        tmp = Mid + 1 - tr.get(Mid+1);
        if(tmp<o)L=Mid; else R=Mid;
    }
    return R;
}

int main() {
    int n; cin >> n;
    tr.init(n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    reverse(a, a + n);
    for(int i = 0; i < n; ++i) {
        ra[i] = tr.get(a[i]);
        tr.set(a[i] + 1);
    }
    tr.init(n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    reverse(a, a + n);
    for(int i = 0; i < n; ++i) {
        rb[i] = tr.get(a[i]);
        tr.set(a[i] + 1);
    }

    int carry = 0;
    for(int i = 1; i < n; ++i) {
        rc[i] = (ra[i] + rb[i] + carry);
        carry = 0;
        if(rc[i] >= (i+1)) {
            rc[i] -= i + 1;
            carry = 1;
        }
    }
    reverse(rc, rc + n);

    tr.init(n);
    for(int i = 0; i < n; ++i) {
        c[i] = getAns(rc[i]);
        tr.set(c[i] + 1);
    }
    for(int i = 0; i < n; ++i) printf("%d ",c[i]);
    return 0;
}