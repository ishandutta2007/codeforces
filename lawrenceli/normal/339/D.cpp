#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 18;

int n, m;
int a[1<<MAXN];
int tree[1<<MAXN];

void init(int cur, bool b, int lt, int rt) {
    if (lt + 1 == rt) tree[cur] = a[lt];
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, b^1, lt, mid);
        init(2*cur+1, b^1, mid, rt);
        if (!b) tree[cur] = tree[2*cur] | tree[2*cur+1];
        else tree[cur] = tree[2*cur] ^ tree[2*cur+1];
    }
}

void update(int cur, bool b, int lt, int rt, int p, int val) {
    if (lt + 1 == rt) tree[cur] = val;
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(2*cur, b^1, lt, mid, p, val);
        else update(2*cur+1, b^1, mid, rt, p, val);
        if (!b) tree[cur] = tree[2*cur] | tree[2*cur+1];
        else tree[cur] = tree[2*cur] ^ tree[2*cur+1];
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<(1<<n); i++) scanf("%d", &a[i]);
    init(1, (n%2)^1, 0, 1<<n);
    for (int i=0; i<m; i++) {
        int p, val;
        scanf("%d %d", &p, &val);
        p--;
        update(1, (n%2)^1, 0, 1<<n, p, val);
        printf("%d\n", tree[1]);
    }
}