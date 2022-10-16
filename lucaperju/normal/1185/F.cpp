#include <bits/stdc++.h>
/// mai usor decat B-u
using namespace std;
int dp[1200];
void baga (int pz)
{
    for(int i=pz;i<=(1<<10)-1;i=(i+1)|pz)
        ++dp[i];
}
struct ura
{
    int a,pz;
};
vector <ura> cst[1200];
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int main()
{
    int t,n,m,i,j,nc;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>nc;
        int sc=0;
        for(j=1;j<=nc;++j)
        {
            int a;
            cin>>a;
            sc+=(1<<(a-1));
        }
        baga(sc);
    }
    for(i=1;i<=m;++i)
    {
        int cstc,nc;
        cin>>cstc>>nc;
        int sc=0;
        for(j=1;j<=nc;++j)
        {
            int a;
            cin>>a;
            sc+=(1<<(a-1));
        }
        cst[sc].push_back({cstc,i});
    }
    for(i=0;i<(1<<10);++i)
        if(cst[i].size())
            sort(cst[i].begin(),cst[i].end(),cmp);
    int bst=0,cstf=2000000000,rza=1,rzb=2;
    for(i=0;i<(1<<10);++i)
        for(j=0;j<(1<<10);++j)
        {
            if(cst[i].size() && cst[j].size() && i!=j)
            {
                if(dp[i|j]>bst)
                {
                    bst=dp[i|j];
                    cstf=cst[i][0].a+cst[j][0].a;
                    rza=cst[i][0].pz;
                    rzb=cst[j][0].pz;
                }
                if(dp[i|j]==bst && cst[i][0].a+cst[j][0].a<cstf)
                {
                    cstf=cst[i][0].a+cst[j][0].a;
                    rza=cst[i][0].pz;
                    rzb=cst[j][0].pz;
                }
            }
            else if (cst[i].size()>1 && i==j)
            {
                if(dp[i]>bst)
                {
                    bst=dp[i];
                    cstf=cst[i][0].a+cst[i][1].a;
                    rza=cst[i][0].pz;
                    rzb=cst[i][1].pz;
                }
                if(dp[i|j]==bst && cst[i][0].a+cst[i][1].a<cstf)
                {
                    cstf=cst[i][0].a+cst[i][1].a;
                    rza=cst[i][0].pz;
                    rzb=cst[i][1].pz;
                }
            }
        }
    cout<<rza<<' '<<rzb;
    return 0;
}