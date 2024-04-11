#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct data {
    int l, r, i;
};

const int MAXN = 200010;

int n, m, p[MAXN], pnt, ind[MAXN], sieve[MAXN];
ll num[MAXN], bit[MAXN], ans[MAXN];
vector<int> adj[MAXN];
data arr[MAXN];

bool cmp(data d1, data d2) {
    return d1.l != d2.l ? d1.l < d2.l : d1.r < d2.r;
}

ll query(int i) {
    ll ret = 0;
    for (i+=2; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void update(int i, int p) {
    for (i+=2; i<MAXN; i+=i&-i) bit[i] += p;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &p[i]);
        ind[p[i]] = i;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            adj[i].push_back(j);
            if (i != j) adj[j].push_back(i);
        }
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &arr[i].l, &arr[i].r);
        arr[i].i = i;
        arr[i].l--; arr[i].r--;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<adj[p[i]].size(); j++) sieve[adj[p[i]][j]]++;
        num[i+1] = num[i] + sieve[p[i]];
    }
    sort(arr, arr + m, cmp);
    for (int i=0; i<n; i++) {
        int j;
        for (j = pnt; j<m && arr[j].l == i; j++) {
            ans[arr[j].i] = num[arr[j].r + 1] - num[arr[j].l] - query(arr[j].r) + query(arr[j].l - 1);
        }
        pnt = j;
        for (int k=0; k<adj[p[i]].size(); k++) update(ind[adj[p[i]][k]], 1);
    }
    for (int i=0; i<m; i++) printf("%I64d\n", ans[i]);
}