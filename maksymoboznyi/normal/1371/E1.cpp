#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, p, a[N];
vector<int> ans;

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    a[n + 1] = 1e9;
    int cur = 1;
    for (int x = 1; x <= 2000; x++) {
        bool can = 1;
        cur = 1;
        for (int i = 1; i <= n; i++) {
            while (a[cur] <= x + i - 1)
                cur++;
            int k = cur - i;
            if (k % p == 0)
                can = 0;
        }
        if (can)
            ans.pb(x);
    }
    cout << ans.size() << "\n";
    for (auto x: ans)
        cout << x << ' ';
    return 0;
}