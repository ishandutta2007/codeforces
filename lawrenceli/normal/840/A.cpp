#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 200100;

int n, a[maxn], ans[maxn];
pair<int, int> b[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i].A;
        b[i].B = i;
    }

    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0; i < n; i++) ans[b[i].B] = a[n - 1 - i];
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}