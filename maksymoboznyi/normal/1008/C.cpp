#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const long long inf = 2e18;
const int N = 1e5+5;

int n, a[N];
pair<int, int> b[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b+1, b+n+1);
    int ans = 0, cur = 1;
    for (int i = 1; i <= n; i++)
    {
        while (cur <= n && b[cur].first <= b[i].first)
            cur++;
       // cout << i << ' '  << cur << ' ' << b[cur].first << ' ' << b[i].first << endl;
        if (cur > n)
            break;
        ans++;
        cur++;
    }
    cout << ans;
    return 0;
}