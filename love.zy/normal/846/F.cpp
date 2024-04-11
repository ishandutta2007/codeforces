#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn=1000006;
vector<int> g[maxn];
double ans,tot;
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=1000000;i++)g[i].pb(0);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        g[x].pb(i);
    }
    for(int i=1;i<=1000000;i++)g[i].pb(n+1);
    tot=(double)n*(double)n;
    ans=0;
    for(int i=1;i<=1000000;i++)
    {
        double sum=0;
        for(unsigned int j=0;j+1<g[i].size();j++)
        {
            double l=g[i][j]+1,r=g[i][j+1]-1;
            if(l>r)continue;
            double u=r-l+1;
            sum+=u*u;
        }
        ans+=tot-sum;
    }
    printf("%.6lf\n",ans/tot);
    return 0;
}