#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int n, a[200005], ans = 0;
int main()
{
    cin >> n;
    n*=2;
    int k;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, s);
        cin >> k;
        a[k]++;
        s++;
        if (a[k] % 2 == 0)
        {
            a[k] = 0;
            s -= 2;
        }
    }
    ans = max(ans, s);
    cout << ans;
    return 0;
}