#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2000100;

int n, q, a[MAXN], nxt[MAXN], vis[MAXN];
ll b;

void go() {
    memset(vis, -1, sizeof(vis));
    ll cur = 0;
    for (int i=0, j=0; i<2*n; i++) {
        while (j<2*n && cur+a[j]<=b) cur += a[j], j++;
        nxt[i] = j;
        cur -= a[i];
    }

    int k = 0;
    for (int i=0; i<n; i=nxt[i]) k++;
/*
    for (int i=0; i<n; i++) cout << nxt[i] << ' ';
    cout << endl;
*/
    if (k == 1) {
        printf("1\n");
        return;
    }

    for (int i=1; i<=nxt[0]; i++) {
        int j = i;
        for (int l=0; l<k-1; j=nxt[j], l++) {
            if (vis[j] == l) break;
            vis[j] = l;
        }

        if (j>=i+n) {
            printf("%d\n", k-1);
            return;
        }
    }
    printf("%d\n", k);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> a[i], a[i+n] = a[i];
    for (int i=0; i<q; i++) {
        cin >> b;
        go();
    }
}