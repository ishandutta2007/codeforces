#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define pb push_back
using namespace std;
struct Point
{
    int x, y;
}p[1010];
int n, k, cnt, d[1000010], g[1010][1010], vis[1010];
vector<int> Map[1010];

int dis(int i, int j)
{
     return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
}
bool dfs(int cnt ,int m)
{
    if(cnt > n) return 1;
    if(vis[cnt]) return dfs(cnt + 1 ,m) ;
    int Len = Map[cnt].size();
    FOR(i, 0, Len - 1)
    {
         m += !vis[Map[cnt][i]] ;
         vis[Map[cnt][i]] ++;
    }
    if(m <= k && dfs(cnt + 1 ,m)) return 1;
    int temp = m ;
    FOR(i, 0, Len - 1)
    {
        vis[Map[cnt][i]] --;
        m -= !vis[Map[cnt][i]];
    }
    if(Map[cnt].size() != 1)
    {
        vis[cnt] ++;
        if(m + 1 <= k && m + 1 < temp && dfs(cnt + 1, m + 1))
            return true;
        vis[cnt] --;
    }
    return false;
}
bool check(int Dis)
{
    memset(vis, 0, sizeof vis);
    FOR(i, 1, n)
        Map[i].clear();
    FOR(i, 1, n)
        FOR(j, i + 1, n)
            if(g[i][j] > Dis)
            {
                Map[i].pb(j);
                Map[j].pb(i);
            }
    return dfs(1 ,0) ;
}
int Two_Find(int left, int right)
{
    while(left < right)
    {
       int mid = (left + right) >> 1;
       if(check(d[mid]))  right = mid;
       else  left = mid + 1;
    }
    return left;
}

int main()
{
    scanf("%d %d", &n, &k);
    FOR(i, 1, n)
        scanf("%d %d", &p[i].x, &p[i].y);
    FOR(i, 1, n)
        FOR(j, 1, n)
            d[++ cnt] = g[i][j] = dis(i, j);
    sort(d, d + cnt + 1);
    int num = unique(d ,d + cnt + 1) - d - 1;
    int mx = Two_Find(0 ,num);
    check(d[mx]) ;
    bool first = false ;
    for(int i = n ;i >= 1 ; --i)
        if(vis[i])
        {
              if(first)  putchar(' ') ;
              printf("%d" ,i) ;
              k --;
              first = true ;
        }
    for(int i = n ;i >= 1 && k > 0 ; --i)
        if(!vis[i])
        {
            if(first)  putchar(' ') ;
            printf("%d" ,i) ;
            k --;
            first = true ;
        }
    return 0;
}