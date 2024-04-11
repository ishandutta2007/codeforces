#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 200;
const long long inf = 2e18;

int n;

int pos1[N], pos2[N], a[N];

signed main()
{
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
        if (pos1[a[i]] == 0)
            pos1[a[i]] = i;
        else
            pos2[a[i]] = i;
    }
    int now = 1;
    while (now <= 2*n)
    {
        while (now <= 2*n && a[now] == a[now+1])
            now += 2;
        if (now > 2*n)
            break;
        int pos = now+1;
        for (int i = now+1; i <= 2*n; i++)
        if (a[now] == a[i])
        {
            pos = i;
            break;
        }
        for (int i = pos; i > now+1; i--)
            swap(a[i], a[i-1]), ans++;
    }
    cout << ans;
    return 0;
}