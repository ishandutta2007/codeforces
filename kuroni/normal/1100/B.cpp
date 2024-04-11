#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int N = 100005;

int ans = 0, n, m, a, cnt[N];
multiset<int> se;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        se.insert(0);
    while (m--)
    {
        scanf("%d", &a);
        se.erase(se.find(cnt[a]));
        se.insert(++cnt[a]);
        if (*se.begin() > ans)
        {
            ans++;
            printf("1");
        }
        else
            printf("0");
    }
}