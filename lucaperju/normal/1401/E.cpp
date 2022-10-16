#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int tip,x,y;
}v[200005];
int aib[1000006];
int lsb (int x)
{
    return x&-x;
}
void update (int pz, int val)
{
    for(;pz<=1000000;pz+=lsb(pz))
        aib[pz]+=val;
}
int query (int pz)
{
    int rz=0;
    for(;pz>0;pz-=lsb(pz))
        rz+=aib[pz];
    return rz;
}
bool cmp (ura a, ura b)
{
    if(a.x<b.x)
        return true;
    if(b.x<a.x)
        return false;
    return a.tip<b.tip;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,i;
    cin>>n>>m;
    int j=0,cnt=0;
    long long rz=0;
    for(i=1;i<=n;++i)
    {
        int y,a,b;
        cin>>y>>a>>b;
        if(a==0)
        {
            v[++j]={1,b+1,y};
            update(y,1);
        }
        else
        {
            v[++j]={2,a,y};
            ++cnt;
        }
    }
    for(i=1;i<=m;++i)
    {
        int x,a,b;
        cin>>x>>a>>b;
        if(a==0)
            v[++j]={3,x,b};
        else
            v[++j]={4,x,a};
    }
    sort(v+1,v+j+1,cmp);
    int pz=1;
    for(int xc=1;xc<1000000;++xc)
    {
        while(v[pz].tip==1 && v[pz].x==xc)
        {
            update(v[pz].y,-1);
            ++pz;
        }
        while(v[pz].tip==2 && v[pz].x==xc)
        {
            update(v[pz].y,1);
            ++pz;
        }
        while(v[pz].tip==3 && v[pz].x==xc)
        {
            int st=0;
            int dr=v[pz].y;
            if(dr==1000000)
                ++rz;
            rz+=query(dr);
            ++pz;
        }
        while(v[pz].tip==4 && v[pz].x==xc)
        {
            int st=v[pz].y;
            int dr=1000000;
            if(st==0)
                ++rz;
            rz+=query(dr)-query(st-1);
            ++pz;
        }
    }
    while(v[pz].tip==1 && v[pz].x==1000000)
    {
        update(v[pz].y,-1);
        ++pz;
    }
    rz+=query(1000000)+1LL;
    cout<<rz-cnt;
}