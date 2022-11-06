#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int rep[N];
int n, m, k, x;
bool isHappy[N];
int find(int w)
{
    return w == rep[w]? w: rep[w] = find(rep[w]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    isHappy[b] |= isHappy[a];
    rep[a] = b;
}
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &x);
        isHappy[x] = true;
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &x);
        isHappy[n + x] = true;
    }
    for(int i = 0; i < n + m; i++)
        rep[i] = i;
    x = 0;
    int y = 0;
    do
    {
        Union(x, y + n);
        x++;
        if(x == n) x = 0;
        y++;
        if(y == m) y = 0;
    }
    while(x != 0 || y != 0);
    for(int i = 0; i < n + m; i++)
    {
        if(isHappy[find(i)] == false)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}