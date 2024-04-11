#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, a[200005] = {0}, p[200005] = {0}, v[200005] = {0}, r = 0, ir = 0;
int main()
{
    map<int, int> m;
    stack<int> s;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        m[a[i]] = i;
        v[i] = 1;
        if (m[a[i] - 1] != 0)
        {
            p[i] = m[a[i] - 1];
            v[i] = v[p[i]] + 1;
        }
        if (v[i] > r)
        {
            r = v[i];
            ir = i;
        }
    }
    while (ir != 0)
    {
        s.push(ir);
        ir = p[ir];
    }
    cout << r << '\n';
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}