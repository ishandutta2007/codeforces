#include <bits/stdc++.h>

using namespace std;

long long inf = 1e9;
int n;
long long a[500005];
long long ans[500005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i+n] = a[i];
    int pivot = -1;
    for (int i = 1; i <= n; ++i) if (a[i+1] > a[i]) pivot = i;
    if (pivot < 0) {
        if (a[1] == 0) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++i) cout << 1 << ' ';
            cout << endl;
            return 0;
        }
        else return cout << "NO" << endl, 0;
    }
    //pivot + 1 => pivot + n
    ans[pivot + 1] = ans[(pivot + 1) % n] = a[pivot + 1];
    ans[pivot + n] = a[pivot + n];
    long long step = (inf - ans[pivot + n]) / a[pivot + 1] + 1;
    ans[pivot + n] += step * a[pivot + 1];
    ans[pivot % n] = ans[pivot + n];
    for (int i = pivot + n - 1; i > pivot + 1; --i) {
        ans[i] = ans[i + 1] + a[i];
        ans[i % n] = ans[i];
    }
    cout << "YES" << endl;
    for (int i = 1; i < n; ++i) cout << ans[i] << ' ';
    cout << ans[0] << endl;
    return 0;
}