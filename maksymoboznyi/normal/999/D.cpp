#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;
const int N = 2e5+5;
const long long inf = 2e18;

int a[N], kol[N], n, m, ans;
stack<int> g[N];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], kol[a[i]%m]++, g[a[i]%m].push(i);
    int pos = -1;
    for (int i = 1; i <= m; i++)
        if (kol[i-1] < n/m)
    {
        pos = i-1;
        break;
    }
    if (pos == -1)
    {
        cout << "0\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        return 0;
    }
    int cur = 0;
    stack<int> q;
    for (int i = 0; i < m; i++)
        if (kol[i] > n/m)
            q.push(i);
    int ans = 0;
    for (int i = 0; i < m; i++)
        if (kol[i] > n/m)
            q.push(i);
        else
        {
            //cout << i << endl;
            while (kol[i] < n/m)
            {
                int pos = q.top();
                int del;
                if (pos > i)
                    del = m-pos+i;
                else
                    del = i-pos;

                //cout <<pos<< ' ' << del << endl;
                if (g[pos].size()-n/m <= n/m-kol[i])
                {

                    q.pop();
                    while (g[pos].size() != n/m)
                    {
                        int c = g[pos].top();
                       // cout << c << ' ' << kol[i] << endl;
                        g[pos].pop();
                        a[c] += del;
                        kol[i]++;
                        ans += del;
                    }
                }else
                {
                    while (kol[i] != n/m)
                    {
                        kol[i]++;
                        int c= g[pos].top();
                        g[pos].pop();
                       // cout << '*'<<c << ' ' << kol[i] << endl;
                        a[c] += del;
                        ans += del;
                    }
                }
            }
            //cout << endl;
        }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}