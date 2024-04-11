#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            cnt[i % k]++;
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        int a = cnt[i];
        int b = n / k - a;
        res += min(a, b);
    }
    cout << res;

    return 0;
}