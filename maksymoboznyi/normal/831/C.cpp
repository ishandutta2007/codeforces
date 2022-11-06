#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3000;
ll n, k, a[N], b[N], sum[N], ans, c[N];
bool used[N];
set<ll> ss;
int main()
{
    ss.clear();
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= k; i++)
        sum[i] = sum[i-1] + a[i];
    sort(b+1, b+n+1);
    for (int y = 1; y <= k; y++)
    {
        ll cur = b[1] - sum[y];
        c[0] = cur;
        for (int i = 1; i < N; i++)
            used[i] = false;
        for (int i = 1; i <= k; i++)
            c[i] = c[i-1] + a[i];
        sort(c+1, c+k+1);
        int i1 = 1, j1 = 1;
        bool f = false;
        while (j1 <= n)
        {
            bool t = false;
            while (i1 <= k)
            {
                if (c[i1] == b[j1])
                {
                    i1++;
                    t = true;
                    break;
                }
                i1++;
            }
            if (!t)
            {
                f = true;
                break;
            }
            j1++;
        }
        if (!f)
        {
            ss.insert(cur);
        }
    }
    cout << ss.size() << endl;
    return 0;
}