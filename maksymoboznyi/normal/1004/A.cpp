#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

int a[N], n, kol, d;

int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 2;
    for (int i = 1; i < n; i++)
        if (a[i + 1] - a[i] > 2*d)
            ans+=2;
        else
            if (a[i + 1] - a[i] == 2*d)
                ans++;
    cout << ans;
    return 0;
}