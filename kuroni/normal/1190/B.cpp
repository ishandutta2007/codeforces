#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, cnt = 0, a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int ans = (1LL * n * (n - 1) / 2 % 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans ^= (a[i] & 1);
    }
    sort(a + 1, a + n + 1);
    a[0] = -1;
    for (int i = 1; i < n; i++)
        if (a[i] == a[i + 1])
        {
            cnt++;
            if (a[i] - 1 == a[i - 1])
                return cout << "cslnb", 0;
        }
    cout << (ans == 0 || cnt > 1 ? "cslnb" : "sjfnb");
}