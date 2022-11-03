#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define find findd
const int maxn = 2e5 + 20;
const int inf = (1e9);
int dsu[maxn] = {inf} , p[maxn], a , b , c;
int find(int a)
{
    return ((p[a] == a)? a : (p[a] = find(p[a])));
}
int afind(int a)
{
    if(a == inf)
        return inf;
    return ((dsu[a] == a)? a : (dsu[a] = afind(dsu[a])));
}
int main()
{
    int n , q;
    scanf("%d%d", &n , &q);
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        dsu[i] = i;
    }
    dsu[n] = inf;
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d%d" , &a , &b , &c);
        b--; c--;
        if(a != 3 && b == c)
            continue;
        if(a == 1)
        {
            p[find(b)] = find(c);
        }
        if(a == 2)
        {
            int x = dsu[b + 1];
            int y = find(b);
            while(x <= c && x > b)
            {
                p[find(x)] = y;
                dsu[x] = afind(x + 1);
                x = dsu[x];
            }
        }
        if(a == 3)
        {
            if(b == c || p[find(b)] == p[find(c)])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}