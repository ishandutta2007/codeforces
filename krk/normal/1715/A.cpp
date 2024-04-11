#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n == 1 && m == 1) { printf("0\n"); continue; }
        if (m > n) swap(m, n);
        int res = (m - 1) * 2 + 1 + n - 1;
        cout << res << "\n";
    }
    return 0;
}