#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
typedef long long LL;

struct node
{
    int ls,rs,lg,rg;
    LL sum;
    void cle(int x,int y){ls=rs=sum=0;lg=x;rg=y;}
    bool judge(int x,int y){return lg==x && rg==y;}
    bool one(){return lg==rg;}
    int mid(){return (lg+rg)>>1;}
}tr[10000005];
int cnt=0;

struct SegTree
{
    int rt;
    void init(int l,int r)
    {cnt++;tr[rt=cnt].cle(l,r);}

    void upd(int t)
    {
        int ls=tr[t].ls,rs=tr[t].rs;
        if(ls+rs==0)return;
        tr[t].sum=tr[ls].sum+tr[rs].sum;
    }

    void add(int now,int pos,LL num)
    {
        if(tr[now].one())
        {
            tr[now].sum+=num;
            return;
        }
        int mid=tr[now].mid();
        if(pos<=mid)
        {
            if(tr[now].ls==0)
            {
                tr[++cnt].cle(tr[now].lg,mid);
                tr[now].ls=cnt;
            }
            add(tr[now].ls,pos,num);
        }else
        {
            if(tr[now].rs==0)
            {
                tr[++cnt].cle(mid+1,tr[now].rg);
                tr[now].rs=cnt;
            }
            add(tr[now].rs,pos,num);
        }
        upd(now);
    }

    LL query(int now,int l,int r)
    {
        if(now==0)return 0ll;
        if(tr[now].judge(l,r))return tr[now].sum;
        int mid=tr[now].mid();
        if(r<=mid)return query(tr[now].ls,l,r);
        if(l>mid)return query(tr[now].rs,l,r);
        return query(tr[now].ls,l,mid)+query(tr[now].rs,mid+1,r);
    }
}bit[100005];

int a[100001];
set<int> s[100005];
set<int>::iterator it;
int n,m,opt,l,r;

void jia(int x,int y,LL num)
{
    while(x<=n)
    {
        bit[x].add(bit[x].rt,y,num);
        x+=lowbit(x);
    }
}

LL cal(int p,int u,int d)
{
    LL ret=0;
    while(p>0)
    {
        ret+=bit[p].query(bit[p].rt,u,d);
        p-=lowbit(p);
    }
    return ret;
}

LL query(int x,int y,int l,int r)
{
    return cal(y,l,r)-cal(x-1,l,r);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)bit[i].init(0,n);
    for(int i=1;i<=n;i++)
    {
        int x,num;
        scanf("%d",&x);
        a[i]=x;
        if(s[x].empty())num=0;
        else
        {
            it=s[x].end();
            --it;
            num=*it;
        }
        s[x].insert(i);
        jia(i,num,i-num);
    }
    while(m--)
    {
        scanf("%d%d%d",&opt,&l,&r);
        if(opt==1)
        {
            int t=a[l],le,ri;
            it=s[t].find(l);
            if(it==s[t].begin())le=0;else le=*(prev(it));
            jia(l,le,le-l);
            ++it;
            if(it!=s[t].end())
            {
                ri=*(it);
                jia(ri,l,l-ri);
                jia(ri,le,ri-le);
            }
            s[t].erase(l);
            //new
            a[l]=r;
            it=s[r].upper_bound(l);
            if(it==s[r].begin())le=0;else le=*(prev(it));
            jia(l,le,l-le);
            if(it!=s[r].end())
            {
                ri=*it;
                jia(ri,le,le-ri);
                jia(ri,l,ri-l);
            }
            s[r].insert(l);
        }else 
        {
            long long temp=query(l,r,l,n);
            printf("%lld\n",temp);
        }
    }
	return 0;
}