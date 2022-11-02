#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
struct Point
{
    int pos,weight;
}   a[maxn];
int c[maxn];
int que_[maxn],tot_;
int f[maxn];
int n;

bool cmp(Point a,Point b)
{
    return a.pos<b.pos;
}

inline int lowbit(int t){return t&(-t);}
int query(int t)
{
    if (t==0)   return 0;
    int ans=0;
    for (int i=t;i;i-=lowbit(i))    ans=max(ans,c[i]);
    return  ans;
}
void add(int t,int v)
{
    for (int i=t;i<=tot_;i+=lowbit(i))  c[i]=max(c[i],v);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].pos,&a[i].weight);
        que_[i]=a[i].pos+a[i].weight;
    }
    sort(que_+1,que_+1+n);
    tot_=unique(que_+1,que_+n+1)-(que_+1);
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int pos=upper_bound(que_+1,que_+tot_+1,a[i].pos-a[i].weight)-que_;
        f[i]=query(pos-1)+1;
        pos=lower_bound(que_+1,que_+tot_+1,a[i].pos+a[i].weight)-que_;
        add(pos,f[i]);
        ans=max(f[i],ans);
    }
    printf("%d\n",ans);
}