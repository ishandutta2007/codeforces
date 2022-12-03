#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], c[N];
long long b[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long x = 1, y = 1, z = 1;
    while(x < 1e13) {
        b[m++] = x;
        z = x + y;
        x = y;
        y = z;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt += a[i];
        }
        if (n == 1) {
            if (a[0] == 1) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            continue;
        }
        int x = 0;
        while (cnt > 0) {
            c[x] = 0;
            cnt -= b[x++];
        }
        if (cnt < 0 || b[x - 1] > 1e9) {
            cout << "NO\n";
            continue;
        }
        sort(a, a + n);
        int flag = 1;
        for(int i = x - 1; i >= 0; i--) {
            if (i != x - 1) {
                sort(a, a + n - 1);
                swap(a[n - 2], a[n - 1]);
            }
            a[n - 1] -= b[i];
            if (a[n - 1] < 0) flag = 0;
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}