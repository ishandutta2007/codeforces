#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct node1 {
    int l1, r1, l2, r2;
    bool operator < (const node1 &A) const {
        return l1 > A.l1; 
    }
} a[100001];

struct node2 {
    int l1, r1, l2, r2;
    bool operator < (const node2 &A) const {
        return r1 < A.r1; 
    }
} c[100001];


struct node {
    int e, a;
} f[1600001];

int n, b[400001];
map<int, int> idx;

inline void insert(int k, int Left, int Right, int s, int t) {
    f[k].e = true;
    if (Left == s && Right == t) {
        f[k].a = true;
        return;
    }
    int i = (Left + Right) >> 1;
    if (t <= i)
        insert(k + k, Left, i, s, t);
    else
        if (s > i)
            insert(k + k + 1, i + 1, Right, s, t);
        else
            insert(k + k, Left, i, s, i),
            insert(k + k + 1, i + 1, Right, i + 1, t);
    f[k].a |= f[k + k].a & f[k + k + 1].a;
}

bool calc(int k, int Left, int Right, int s, int t) {
    if (f[k].a)
        return true;
    if (Left == s && Right == t)
        return f[k].e;
    int i = (Left + Right) >>1;
    if (t <= i)
        return calc(k + k, Left, i, s, t);
    else
        if (s > i)
            return calc(k + k + 1, i + 1, Right, s, t);
        else
            return calc(k + k, Left, i, s, i) | calc(k + k + 1, i + 1, Right, i + 1, t);
}

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a[i].l1, &a[i].r1, &a[i].l2, &a[i].r2);
        c[i].l1 = a[i].l1; c[i].l2 = a[i].l2;
        c[i].r1 = a[i].r1; c[i].r2 = a[i].r2;
        b[++cnt] = a[i].l1; b[++cnt] = a[i].l2;
        b[++cnt] = a[i].r1; b[++cnt] = a[i].r2;
    }
    sort(b + 1, b + cnt + 1);
    int m = 0;
    for (int i = 1; i <= cnt; i++)
        if (i == 1 || b[i] != b[i - 1])
            idx[b[i]] = ++m;
        
    bool ok = true;
    for (int x = 0; x < 2; x++) {
        for (int i = 1; i <= n; ++i)
            swap(a[i].l1, a[i].l2), swap(a[i].r1, a[i].r2),
            swap(c[i].l1, c[i].l2), swap(c[i].r1, c[i].r2);
        sort(a + 1, a + n + 1);
        sort(c + 1, c + n + 1);
        int l = 1;
        for (int i = 1; i <= 4 * m; i++)
            f[i].e = f[i].a = 0;
        for (int i = n; i && ok; --i) {
            for (; l <= n && a[l].l1 > c[i].r1; ++l)
                insert(1, 1, m, idx[a[l].l2], idx[a[l].r2]);
            if (calc(1, 1, m, idx[c[i].l2], idx[c[i].r2]))
                ok = false;
        }
    }
    
    if (ok)
        printf("YES\n");
    else
        printf("NO\n");
}