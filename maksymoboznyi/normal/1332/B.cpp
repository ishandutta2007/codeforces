#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int n, a[N], ans[N];
vector<int> q;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i * i <= 1000; i++)
        if (is_prime(i))
            q.pb(i);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], ans[i] = 0;
        int m = 1;
        for (int j = 0; j < 11; j++) {
            int was = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] % q[j] == 0 && ans[i] == 0)
                    ans[i] = m, was = 1;
            if (was)
                m++;

        }
        cout << m - 1 << "\n";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout<< "\n";
    }
    return 0;
}