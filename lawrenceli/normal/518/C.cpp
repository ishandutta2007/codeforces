#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int n, m, k, a[MAXN], b[MAXN], p[MAXN];

int main() {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    long long ans = 0;
    for (int i=0; i<m; i++) {
        cin >> b[i];
        ans += p[b[i]]/k+1;
        if (p[b[i]]) {
            int x = a[p[b[i]]-1];
            swap(a[p[x]], a[p[b[i]]]);
            swap(p[x], p[b[i]]);
        }
    }
    cout << ans;
}