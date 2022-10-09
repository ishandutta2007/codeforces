#include <cstdio>
#include <algorithm>
#include <queue>
#define maxn 1000100
using namespace std;
pair <int, int> t[maxn];
int newt[maxn], n, dr[maxn], w;

void add(int p, int v)
{
    while (p < maxn)
    {
        dr[p] = max(dr[p], v);
        p+=p&(-p);
    }
}

int get(int p)
{
    int s=0;
    while (p > 0)
    {
        s = max(s, dr[p]);
        p-=p&(-p);
    }
    return s;
}
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) 
    {
        scanf("%d", &t[i].first);
        t[i].second=i;
    }
    sort(t+1, t+n+1);
    int ile = 0;
    t[0]=make_pair(-1, 0);
    for (int i=1; i<=n; i++)
    {
        if (t[i].first != t[i-1].first) ile++;
        newt[t[i].second] = ile;
    }
    
    
    //for (int i=1; i<=n; i++) printf("%d ", newt[i]);
    int wyn=0;
    for (int i=1; i<=n; i++)
    {
        w=get(newt[i]-1)+1;
        wyn = max(wyn, w);
        add(newt[i], w);
    }
    printf("%d", wyn);
}