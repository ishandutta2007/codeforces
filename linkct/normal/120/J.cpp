#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int oo = 0x3f3f3f3f;

struct Dat {
    int x,y,id;
};

Dat p[100010];
int a[100010],b[100010],q[100010];
int ans,p1,p2;

bool cmp(Dat a,Dat b) {
    return a.x < b.x;
}

int sqr(int x) {
    return x * x;
}

int dis(Dat a,Dat b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int solve(int l,int r) {
    if (l == r)
        return oo;
    if (r - l == 1) {
        int s = dis(p[l],p[r]);
        if (s < ans) {
            p1 = l;
            p2 = r;
            ans = s;
        }
        return s;
    }
    int mid = (l + r) / 2;
    int d1 = solve(l,mid),d2 = solve(mid + 1,r);
    int d = min(d1,d2);
    int tot = 0;
    for (int i = l; i <= r; i++)
        if (sqr(p[mid].x - p[i].x) <= d)
            q[tot++] = i;
    for (int i = 0; i < tot; i++)
        for (int j = i + 1; j < tot; j++) {
            int tmp = dis(p[q[i]],p[q[j]]);
            if (tmp < d) {
                d = tmp;
                if (tmp < ans) {
                    ans = tmp;
                    p1 = q[i];
                    p2 = q[j];
                }
            }
        }
    return d;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i],&b[i]);
        p[i].x = abs(a[i]);
        p[i].y = abs(b[i]);
        p[i].id = i;
    }
    sort(p + 1,p + n,cmp);
    ans = oo;
    solve(1,n);
    int k1,k2;
    if (a[p[p1].id] != p[p1].x && b[p[p1].id] != p[p1].y)
        k1 = 4;
    else
        if (a[p[p1].id] != p[p1].x)
            k1 = 2;
        else
            if (b[p[p1].id] != p[p1].y)
                k1 = 3;
            else
                k1 = 1;
    if (a[p[p2].id] != p[p2].x && b[p[p2].id] != p[p2].y)
        k2 = 1;
    else
        if (a[p[p2].id] != p[p2].x)
            k2 = 3;
        else
            if (b[p[p2].id] != p[p2].y)
                k2 = 2;
            else
                k2 = 4;
    printf("%d %d %d %d\n",p[p1].id,k1,p[p2].id,k2);
    return 0;
}