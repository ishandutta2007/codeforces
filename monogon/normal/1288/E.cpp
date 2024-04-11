
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, m;
int ans[N][2], a[N], bit[N + N], p[N];

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k <= n + m) {
        bit[k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        ans[i][0] = ans[i][1] = i;
        p[i] = n - i + 1;
        add(n - i + 1, 1);
    }
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        ans[a[i]][0] = 1;
        ans[a[i]][1] = max(ans[a[i]][1], 1 + getSum(n + i) - getSum(p[a[i]]));
        add(p[a[i]], -1);
        p[a[i]] = n + i;
        add(p[a[i]], 1);
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i][0] << " " << max(ans[i][1], 1 + getSum(n + m) - getSum(p[i])) << endl;
    }
}