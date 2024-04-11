#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200100;

int n, a[MAXN], add[MAXN], ans[MAXN];

int get(int k) {
    int ret = 0;
    for (int i=1; i<n; i++)
        if (a[i] < a[(i-1)/k]) ret++;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    int m;
    for (m=n-1; m>0 && 1+m+ll(m)*m>=n; m--);

    for (int i=1; i<n; i++)
        for (int j=0; j<n && (!j || (i-1)/j>=m); j++)
            if (a[i] < a[j]) {
                if (j == 0) add[n-1]++;
                else add[(i-1)/j]++;
                add[(i-1)/(j+1)]--;
            }

    for (int i=n-1, j=0; i>m; i--) {
        j += add[i];
        ans[i] = j;
    }

    for (int i=m; i>0; i--)
        ans[i] = get(i);

    for (int i=1; i<n; i++) cout << ans[i] << ' ';
}