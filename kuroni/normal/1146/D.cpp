#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100000;

int m, a, b;
long long ans = 0;
bool vis[N];

long long get(int r)
{
    long long ans = 1LL * (r / a + 1) * (r % a + 1);
    r -= r % a + 1;
    ans += 1LL * (r + 1) * ((r + 1) / a + 1) / 2;
    return ans;
}

void find_ans(int mod, int mx = 0)
{
    if (mx > m)
        return;
    vis[mod] = true;
    ans += get(m - mod) - get(mx - mod - 1);
    while (mod < b)
        mod += a;
    if (!vis[(mod - b) % a])
        find_ans((mod - b) % a, max(mx, mod));
}

int main()
{
    scanf("%d%d%d", &m, &a, &b);
    find_ans(0);
    printf("%lld\n", ans);
}