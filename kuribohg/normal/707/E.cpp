#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,m,k,Q,len[2010];
int s[2010],S[2010][2010],x1[2010],y1[2010],x2[2010],y2[2010],tot;
pair<int,int> p[2010][2010];
LL v[2010][2010];
LL BIT[2010][2010];
LL ans[2010];
void Change(int x,int y,LL tar)
{
    for(int i=x;i<=n;i+=(i&(-i)))
        for(int j=y;j<=m;j+=(j&(-j)))
            BIT[i][j]+=tar;
}
LL Query(int x,int y)
{
    LL ans=0;
    for(int i=x;i;i^=(i&(-i)))
        for(int j=y;j;j^=(j&(-j)))
            ans+=BIT[i][j];
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&len[i]);
        for(int j=1;j<=len[i];j++)
            scanf("%d%d%I64d",&p[i][j].first,&p[i][j].second,&v[i][j]);
        s[i]=1;
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int x;
        char str[10];
        scanf("%s",str);
        if(str[0]=='S') scanf("%d",&x),s[x]^=1;
        else
        {
            ++tot,scanf("%d%d%d%d",&x1[tot],&y1[tot],&x2[tot],&y2[tot]);
            for(int o=1;o<=k;o++) S[tot][o]=s[o];
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int o=1;o<=len[i];o++)
            Change(p[i][o].first,p[i][o].second,v[i][o]);
        for(int o=1;o<=tot;o++)
            if(S[o][i]) ans[o]+=Query(x2[o],y2[o])-Query(x1[o]-1,y2[o])-Query(x2[o],y1[o]-1)+Query(x1[o]-1,y1[o]-1);
        for(int o=1;o<=len[i];o++)
            Change(p[i][o].first,p[i][o].second,-v[i][o]);
    }
    for(int i=1;i<=tot;i++) printf("%I64d\n",ans[i]);
    return 0;
}