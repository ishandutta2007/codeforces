#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int maxn=100005;
pair<int,int> ans[maxn];
struct node
{
    int gr,pos,tim,lb;
    void read(int u)
    {
        lb=u;
        scanf("%d%d%d",&gr,&pos,&tim);
    }
    bool operator < (const struct node &p)const
    {return pos<p.pos;}
}a[maxn];
vector<node> cnt[3][2*maxn];

int n,w,h,g1[maxn],g2[maxn];

int main()
{
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++)
    {
        a[i].read(i);
        cnt[a[i].gr][a[i].pos-a[i].tim+100000].pb(a[i]);
    }
    for(int i=1;i<=200000;i++)
    {
        int s=cnt[1][i].size()+cnt[2][i].size();
        if(s==0)continue;
        if(cnt[1][i].size()==0 || cnt[2][i].size()==0)
        {
            for(int j=1;j<=2;j++)
            {
                for(int k=0;k<cnt[j][i].size();k++)
                {
                    node u=cnt[j][i][k];
                    if(u.gr==1)ans[u.lb]=mp(u.pos,h);
                    else ans[u.lb]=mp(w,u.pos);
                }
            }
        }else
        {
            //printf("%d %d %d\n",i,cnt[i][0],cnt[i][1]);
            sort(cnt[1][i].begin(),cnt[1][i].end());
            sort(cnt[2][i].begin(),cnt[2][i].end());
            int x=cnt[1][i].size(),y=cnt[2][i].size();
            //int xx=x,yy=y;
            for(int k=0;k<cnt[1][i].size();k++)
            {
                int r=x-1-k,u=y;
                if(r>=u)g1[k+u]=cnt[1][i][k].lb;
                else g2[r]=cnt[1][i][k].lb;
            }
            for(int k=0;k<cnt[2][i].size();k++)
            {
                int u=y-1-k,r=x;
                if(u>=r)g2[k+r]=cnt[2][i][k].lb;
                else g1[u]=cnt[2][i][k].lb;
            }
            for(int k=0;k<cnt[1][i].size();k++)
                ans[g1[k]]=mp(cnt[1][i][k].pos,h);
            for(int k=0;k<cnt[2][i].size();k++)
                ans[g2[k]]=mp(w,cnt[2][i][k].pos);
        }
    }
    for(int i=1;i<=n;i++)printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}