#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,tot,s[MAXN],d[MAXN];
pair<LL,LL> I[MAXN];
bool Intersect(const pair<LL,LL> &p,const pair<LL,LL> &q)
{
    if(p.first>=q.first&&p.first<=q.second) return true;
    if(p.second>=q.first&&p.second<=q.second) return true;
    if(q.first>=p.first&&q.first<=p.second) return true;
    if(q.second>=p.first&&q.second<=p.second) return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i],&d[i]);
        bool ok=true;
        for(int k=1;k<=tot;k++)
            if(Intersect(I[k],make_pair(s[i],s[i]+d[i]-1)))
                ok=false;
        if(ok)
        {
            printf("%d %d\n",s[i],s[i]+d[i]-1);
            I[++tot]=make_pair(s[i],s[i]+d[i]-1);
            continue;
        }
        LL st=1000000000000000000LL;
        for(int o=0;o<=tot;o++)
        {
            bool ok=true;
            for(int k=1;k<=tot;k++)
            {
                if(Intersect(I[k],make_pair(I[o].second+1,I[o].second+d[i])))
                    ok=false;
            }
            if(ok) st=min(st,I[o].second+1);
        }
        printf("%I64d %I64d\n",st,st+d[i]-1);
        I[++tot]=make_pair(st,st+d[i]-1);
    }
    return 0;
}