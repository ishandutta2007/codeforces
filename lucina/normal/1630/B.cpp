#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, k;
int a[nax];
int b[nax];
int c[nax];
int cnt(int x) {
    return upper_bound(b + 1, b + 1 + n, x) - b - 1;
}

int cnt(int l, int r) {
    return cnt(r) - cnt(l - 1);
}

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n; ++ i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1 ; i <= n ; ++ i)
        c[i] = cnt(i);
    int x = 1, y = n;
    for (int i = 1 ; i <= n ; ++ i) {
        int l = i, r = n, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (c[mid] - c[i - 1] >= n - (c[mid] - c[i - 1]) + k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if (ans == -1) continue;
        if (ans - i < y - x) {
            y = ans, x = i;
        }
    }
    cout << x << ' ' << y << '\n';
    for (int i = 1; i <= n ; ++ i) {
        a[i] = (a[i] >= x && a[i] <= y) ? 1 : -1;
    }
    for (int i = 1 ; i <= n ;) {
        int j = i;
        int s = 0;
        while (j <= n && s <= 0) {
            s += a[j++];
        }
        if (k != 1) {
            cout << i << ' ' << j - 1 << '\n';
            -- k;
        } else {
            cout << i << ' ' << n << '\n';
            break;
        }
      	i = j;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}