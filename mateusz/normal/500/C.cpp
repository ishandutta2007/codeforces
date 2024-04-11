#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1005;
int w[N], b[N], n, k;
bool isSet[N];
int cnt;
int m[N], order[N], tab[N];
int sum(int a, int b)
{
    int ret = 0;
    for(int i = a; i <= b; i++)
        ret += w[tab[i]];
    return ret;
}
void move(int p)
{
    while(p > 1)
    {
        swap(order[tab[p]], order[tab[p - 1]]);
        swap(tab[p], tab[p - 1]);
        p--;;
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    cnt = 0;
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &m[i]);
        if(isSet[m[i]] == false)
        {
            isSet[m[i]] = true;
            order[m[i]] = ++cnt;
            tab[cnt] = m[i];
        }
    }
    int ans = 0;
    for(int i = 1; i <= k; i++)
    {
        ans += sum(1, order[m[i]] - 1);
        move(order[m[i]]);
    }
    printf("%d", ans);
    return 0;
}