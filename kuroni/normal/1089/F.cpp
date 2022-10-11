#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100005;
const long long INF = 1E18 + 7;

int n, mod, tr[N];
long long dst[N];
vector<int> ve, ans;

struct SNode
{
    long long val;
    int u;
};

inline bool operator>(const SNode &a, const SNode &b)
{
    return a.val > b.val;
}

priority_queue<SNode, vector<SNode>, greater<SNode>> pq;

void dijkstra()
{
    fill(dst, dst + mod, INF);
    pq.push((SNode){dst[0] = 0, 0});
    while (!pq.empty())
    {
        SNode u = pq.top();
        pq.pop();
        if (u.val > dst[u.u])
            continue;
        for (int &v : ve)
            if (dst[(u.val + v) % mod] > u.val + v)
            {
                int tar = (u.val + v) % mod;
                tr[tar] = v;
                pq.push((SNode){dst[tar] = u.val + v, tar});
            }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            ve.push_back(i);
            ve.push_back(n / i);
        }
    sort(ve.begin(), ve.end());
    if (ve.empty())
        return printf("NO"), 0;
    mod = *ve.begin();
    dijkstra();
    if (dst[mod - 1] > n)
        return printf("NO"), 0;
    printf("YES\n");
    for (long long cur = dst[mod - 1]; cur != 0; cur -= tr[cur % mod])
        ans.push_back(n / tr[cur % mod]);
    printf("%d\n", ans.size() + 1);
    for (int &v : ans)
        printf("1 %d\n", v);
    printf("%lld %d\n", (n - dst[mod - 1]) / mod, n / mod);
}