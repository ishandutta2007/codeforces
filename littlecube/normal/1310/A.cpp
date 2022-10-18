#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

pii a[200005];
ll n, r, num, sum;
priority_queue<int> p;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        while (!p.empty() && a[i].first != num)
        {
            sum -= p.top();
            p.pop();
            r += sum;
            num++;
        }
        if (p.empty())
            num = a[i].first;
        p.push(a[i].second);
        sum += a[i].second;
    }
    while (!p.empty())
    {
        sum -= p.top();
        p.pop();
        r += sum;
        num++;
    }
    cout << r;
}