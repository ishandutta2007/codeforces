#include <bits/stdc++.h>

using namespace std;

int n;
long long a[200005];
int b[200005];
int cnt[100];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        long long tmp = a[i];
        while (tmp % 2 == 0) ++b[i], tmp /= 2;
        ++cnt[b[i]];
    }
    int ans = max_element(cnt, cnt + 100) - cnt;
    cout << n - cnt[ans] << endl;
    for (int i = 1; i <= n; ++i) if (b[i] != ans) cout << a[i] << ' ';
    cout << endl;
    return 0;
}