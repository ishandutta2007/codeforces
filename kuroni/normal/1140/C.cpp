#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 300005;

int k, n;
long long ans = 0, cur = 0;
pair<int, int> a[N];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].se, &a[i].fi);
    sort(a + 1, a + n + 1, greater<pair<int, int>>());
    for (int i = 1; i <= n; i++)
    {
        cur += a[i].se; pq.push(a[i].se);
        if (pq.size() > k)
        {
            cur -= pq.top();
            pq.pop();
        }
        ans = max(ans, cur * a[i].fi);
    }
    printf("%lld", ans);
    return 0;
}