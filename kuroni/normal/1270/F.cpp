#include <bits/stdc++.h>
using namespace std;

const int N = 200005, D = 450;

int n, l[N], pre[N], pt[N], cnt[N * D];
char s[N];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '1');
        pt[i] = l[i] = (s[i] == '1' ? i : l[i - 1]);
        for (int j = 1; j <= D && pt[i] > 0; j++, pt[i] = l[pt[i] - 1]) {
            int le = l[pt[i] - 1] - i % j - 1, ri = pt[i] - 1 - i % j;
            ans += (ri < 0 ? 0 : ri / j + 1) - (le < 0 ? 0 : le / j + 1);
        }
    }
    for (int i = 1; i <= n / D; i++) {
        int mi = n * (i - 1), cur = 0;
        for (int j = 1; j <= n; j++) {
            for (; cur < pt[j]; cur++) {
                cnt[cur - pre[cur] * i + mi]++;
            }
            ans += cnt[j - pre[j] * i + mi];
        }
        for (int j = 0; j < pt[n]; j++) {
            cnt[j - pre[j] * i + mi]--;
        }
    }
    cout << ans;
}