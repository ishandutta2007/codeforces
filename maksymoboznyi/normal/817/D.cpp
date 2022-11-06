#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll n, a[1000006], l[1000006], r[10000006];
stack<ll> s1, s2;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (!s1.empty() && a[s1.top()] < a[i])
            s1.pop();
        if (s1.size() > 0)
        l[i] = s1.top();
        s1.push(i);
    }
    for (int i = 1; i <= n; i++)
        r[i] = n+1;
    for (int i = n; i > 0; i--)
    {
        while (!s2.empty() && a[s2.top()] <= a[i])
            s2.pop();
        if (s2.size() > 0)
            r[i] = s2.top();
        s2.push(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (i-l[i])*(r[i]-i)*a[i];
    while (s1.size() > 0)
        s1.pop();
    while (s2.size() > 0)
        s2.pop();
    for (int i = 1; i <= n; i++)
        l[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        while (!s1.empty() && a[s1.top()] > a[i])
            s1.pop();
        if (s1.size() > 0)
        l[i] = s1.top();
        s1.push(i);
    }
    for (int i = 1; i <= n; i++)
        r[i] = n+1;
    for (int i = n; i > 0; i--)
    {
        while (!s2.empty() && a[s2.top()] >= a[i])
            s2.pop();
        if (s2.size() > 0)
            r[i] = s2.top();
        s2.push(i);
    }

    for (int i = 1; i <= n; i++)
        ans -= (i-l[i])*(r[i]-i)*a[i];
    cout << ans << endl;
    return 0;
}