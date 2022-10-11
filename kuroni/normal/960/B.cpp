#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, x, y, u, a[N];
long long ans = 0;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        pq.push(abs(u - a[i]));
    }
    for (int i = 1; i <= x + y; i++)
    {
        int u = pq.top();
        pq.pop(); pq.push(abs(u - 1));
    }
    while (!pq.empty())
    {
        int u = pq.top();
        ans += 1LL * u * u;
        pq.pop();
    }
    cout << ans;
}