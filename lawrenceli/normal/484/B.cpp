#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;
const int MAXA = 2000100;

int n, b[MAXA], nxt[MAXA];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        b[a] = 1;
    }

    nxt[0] = -1;
    for (int i=1; i<MAXA; i++) {
        if (b[i]) nxt[i] = i;
        else nxt[i] = nxt[i-1];
    }

    int ans = 0;
    for (int i=1; i<MAXA; i++) {
        if (!b[i]) continue;
        for (int j=i+i; j<MAXA; j+=i) {
            if (nxt[j-1] == -1) continue;
            int k = nxt[j-1]-(j-i);
            if (k>=0 && k<i) ans = max(ans, k);
        }
    }

    cout << ans << '\n';
}