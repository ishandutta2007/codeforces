#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, ans[N], a = 1, del, used[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ans[n] = n / 2;
    a = n / 2;
    ans[n] = a;
    del = 2;
    for (int i = n - 1; i > 1; i--) {
        //cout << a << ' ' << del << endl;
        used[a * del] = 1;

        while (a * del > n || used[a * del]) {
            if (a * del > n)
                a--, del = 2;
            else
                del++;
        }
        ans[i] = a;
    }
    for (int i = 2; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}