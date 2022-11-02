#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200100;

int n, bit[MAXN], val[MAXN];
pii ar[MAXN];

int qry(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret = max(ret, bit[i]);
    return ret;
}

void upd(int i, int v) {
    for (i++; i<MAXN; i+=i&-i) bit[i] = max(bit[i], v);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ar[i].first >> ar[i].second;
        val[i] = ar[i].first + ar[i].second;
    }
    sort(val, val+n);
    sort(ar, ar+n);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int x = ar[i].first, w = ar[i].second;
        int j = upper_bound(val, val+n, x-w)-val-1;
        int v = qry(j) + 1;
        ans = max(ans, v);
        int k = lower_bound(val, val+n, x+w)-val;
        upd(k, v);
    }
    cout << ans;
}