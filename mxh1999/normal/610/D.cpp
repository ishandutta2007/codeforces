#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

#define maxn 100010
struct Ques
{
    int x,y1,y2,op;
}   a[maxn<<1];
struct Seg
{
    ll num,tag,sum;
}   seg[800010];
int num[maxn<<1],tot;
int n,m;
ll ans;
bool cmp(Ques a,Ques b)
{
    return a.x<b.x;
}
void update(int t)
{
    if (seg[t].tag==0)  seg[t].sum=seg[t<<1].sum+seg[t<<1|1].sum;else seg[t].sum=seg[t].num;
}
void build(int t,int l,int r)
{
    if (l==r)
    {
        seg[t].num=num[l+1]-num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    seg[t].num=seg[t<<1].num+seg[t<<1|1].num;
}
void insert(int t,int l,int r,int ql,int qr,int val)
{
    if (l==ql && r==qr)
    {
        seg[t].tag+=val;
        if (seg[t].tag==0)
        {
            if (l==r)   seg[t].sum=0;else seg[t].sum=seg[t<<1].sum+seg[t<<1|1].sum;
        }   else seg[t].sum=seg[t].num;
        return;
    }
    int mid=(l+r)>>1;
    if (qr<=mid)    insert(t<<1,l,mid,ql,qr,val);else
    if (ql>mid) insert(t<<1|1,mid+1,r,ql,qr,val);else
    {
        insert(t<<1,l,mid,ql,mid,val);
        insert(t<<1|1,mid+1,r,mid+1,qr,val);
    }
    update(t);
}
int main()
{
    read(n);
    for (int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        read(x1),read(y1),read(x2),read(y2);
        if (x1>x2)  swap(x1,x2);
        if (y1>y2)  swap(y1,y2);
        y2++,x2++;
        num[++tot]=y1;
        num[++tot]=y2;
        m++;
        a[m].x=x1,a[m].y1=y1,a[m].y2=y2,a[m].op=1;
        m++;
        a[m].x=x2,a[m].y1=y1,a[m].y2=y2,a[m].op=-1;
    }
    sort(num+1,num+tot+1);
    tot=unique(num+1,num+tot+1)-(num+1);
    n=tot-1;
    build(1,1,n);
    sort(a+1,a+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        a[i].y1=lower_bound(num+1,num+tot+1,a[i].y1)-num;
        a[i].y2=lower_bound(num+1,num+tot+1,a[i].y2)-num;
        a[i].y2--;
    }
    int lastx=0;
    for (int i=1;i<=m;i++)
    {
        if (a[i].x!=lastx)
        {
            ans+=(ll)(a[i].x-lastx)*seg[1].sum;
            lastx=a[i].x;
        }
        insert(1,1,n,a[i].y1,a[i].y2,a[i].op);
    }
    cout<<ans<<endl;
    return 0;
}