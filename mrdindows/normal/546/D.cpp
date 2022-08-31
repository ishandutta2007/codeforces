#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
int a[MAXN + 1], b[MAXN + 1];
long long cnt[5 * MAXN + 10], sum[5 * MAXN + 10], p[5 * MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 2; i <= 5 * MAXN; i++) {
        if(!p[i]) {
            for (int j = i + i; j <= 5 * MAXN; j += i)
                p[j] = i;
        }
    }
    for(int i = 1; i <= 5 * MAXN; i++) {
        int cur = 0;
        int d = i;
        while(p[d]) {
            d /= p[d];
            cur++;
        }
        cnt[i] = cur + (d > 1);
    }
    for(int i = 1; i <= 5 * MAXN; i++)
        sum[i] = sum[i - 1] + cnt[i];
    for(int i = 0; i < n; i++) {
        cout << sum[a[i]] - sum[b[i]] << '\n';
    }
    return 0;
}