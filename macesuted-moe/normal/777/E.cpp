#include <bits/stdc++.h>
using namespace std;

long long f[100005];

struct sround
{
    long long a, b, h;
} a[100005];
bool cmp(sround x, sround y)
{
    return (x.b == y.b) ? x.a > y.a : x.b > y.b;
}

struct node
{
    long long w, h;
    bool operator<(const node &rhs) const
    {
        return h < rhs.h;
    }
};

priority_queue<node> q;

int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].h);
    sort(a + 1, a + n + 1, cmp);
    q.push((node){0, 0});
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        while (q.top().w >= a[i].b)
            q.pop();
        f[i] = q.top().h + a[i].h;
        q.push((node){a[i].a, q.top().h + a[i].h});
        ans = max(ans, f[i]);
    }
    printf("%lld\n", ans);
    return 0;
}