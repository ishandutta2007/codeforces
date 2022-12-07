#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

struct seg
{
    int l,r,h;
    void read(){scanf("%d%d%d",&h,&l,&r);}
    bool operator < (const struct seg p)const
    {return l<p.l || (l==p.l && r<p.r);}
}a[100005];
struct node
{
    int r,h;
    bool operator < (const struct node p)const
    {return h<p.h;}
};
priority_queue<node> q;
int n,now=0,pos,rr=-1e9-7;

typedef pair<int,int> pii;
vector< pii > ans;

int f[200005],fk[200005],cnt=0;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].read();
        rr=max(rr,a[i].r);
        f[2*i-1]=a[i].l;
        f[2*i]=a[i].r;
    }
    sort(f+1,f+2*n+1);
    fk[1]=f[1];cnt=1;
    for(int i=2;i<=2*n;i++)if(f[i]!=f[i-1])fk[++cnt]=f[i];
    sort(a+1,a+n+1);
    int label=1,u=1;pos=fk[1];
    while(u<=cnt)
    {
        while(label<=n && a[label].l<=pos)
        {
            q.push({a[label].r,a[label].h});
            label++;
        }
        while(!q.empty() && q.top().r<=pos)q.pop();
        if(q.empty())
        {
            if(now!=0)
            {
                ans.pb(mp(pos,now));
                now=0;
                ans.pb(mp(pos,now));
            }
            pos=fk[++u];
            continue;
        }
        if(q.top().h!=now)
        {
            ans.pb(mp(pos,now));
            now=q.top().h;
            ans.pb(mp(pos,now));
        }
        pos=fk[++u];
        //printf("111  :   %d %d\n",pos,u);
    }
    printf("%d\n",ans.size());
    for(pii p : ans)printf("%d %d\n",p.first,p.second);
    return 0;
}