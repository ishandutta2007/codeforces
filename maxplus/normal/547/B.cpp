#include <iostream>
#include <stack>
#define N 200003
#define f first
#define s second

using namespace std;

int dr[N], dl[N], n, a[N], bs[N];
stack<pair<int, int>> q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = a[n + 1] = 0;
    q.push({0, n + 1});
    for (int i = n; i > 0; --i)
    {
        while (q.top().f >= a[i])
            q.pop();
        dr[i] = q.top().s - i;
        q.push({a[i], i});
    }
    while (q.size())
        q.pop();
    q.push({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        while (q.top().f >= a[i])
            q.pop();
        dl[i] = i - q.top().s;
        q.push({a[i], i});
    }
    for (int i = 1; i <= n; ++i)
        bs[dl[i] + dr[i] - 1] = max(bs[dl[i] + dr[i] - 1], a[i]);
    int ans = 0;
    for (int l = n; l > 0; --l)
        bs[l] = (ans = max(ans, bs[l]));
    for (int i = 1; i <= n; ++i)
        cout << bs[i] << ' ';
    return 0;
}