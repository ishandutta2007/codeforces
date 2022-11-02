#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, k, t, ans, A[100010][2], par[100010], v[100010], e[100010];
int Find(int x){if(x==par[x])return x;return par[x]=Find(par[x]);}
void Union(int a, int b)
{
    a=Find(a);
    b=Find(b);
    if(a==b)
    {
        e[a]++;
        return;
    }
    par[b]=a;
    v[a]+=v[b];
    v[b]=0;
    e[a]+=e[b];
    e[b]=0;
    e[a]++;
}
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &m);
        ans=0;
        for(i=0;i++<n;)par[i]=i,v[i]=1,e[i]=0;
        for(i=0;i++<m;)
        {
            scanf("%d %d", &A[i][0], &A[i][1]);
            if(A[i][0]!=A[i][1])
            {
                Union(A[i][0], A[i][1]);
            }
        }
        for(i=0;i++<n;)
        {
            if(v[i]>1)
            {
                if(e[i]==v[i]-1)
                {
                    ans+=e[i];
                }
                else
                {
                    ans+=(e[i]+1);
                }
            }
        }
        printf("%d\n", ans);
    }
}