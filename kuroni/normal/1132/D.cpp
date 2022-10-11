#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 200005, K = 200005;
const long long INF = 1E13 + 7;

int n, k;
long long a[N], b[N];

struct SNode
{
    long long pos, lef;
    int ind;
};
vector<SNode> que[K];


void push(SNode u)
{
    if (u.pos <= k)
        que[u.pos].push_back(u);
}

bool check(long long x)
{
    for (int i = 1; i <= k; i++)
        que[i].clear();
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        push((SNode){a[i] / b[i] + 1, a[i] % b[i], i});
    for (int i = 1; i < k; i++)
    {
        ++cnt;
        while (!que[i].empty())
        {
            SNode u = que[i].back();
            que[i].pop_back();
            --cnt;
            if (cnt < 0)
                return false;
            u.lef += x;
            u.pos += u.lef / b[u.ind];
            u.lef %= b[u.ind];
            push(u);
        }
    }
    return true;
}

long long solve()
{
    long long l = 0, r = INF;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }
    return l > INF ? -1 : l;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld", b + i);
    printf("%lld", solve());
}