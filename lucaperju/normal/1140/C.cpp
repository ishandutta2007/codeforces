#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long tmp,val;
}v[300005];
long long heap[300003],elemx=0;
bool cmp (ura a, ura b)
{
    if(a.val>b.val)
        return true;
    return false;
}
void baga(long long val)
{
    heap[++elemx]=val;
    long long poz=elemx;
    while(poz>1 && heap[poz]<heap[poz/2])
    {
        swap(heap[poz],heap[poz/2]);
        poz>>=1;
    }
}
void scoate ()
{
    long long poz=1;
    swap(heap[1],heap[elemx]);
    --elemx;
    while(poz*2+1<=elemx && heap[poz]>min(heap[poz*2],heap[poz*2+1]))
    {
        if(heap[poz*2]<heap[poz*2+1])
        {
            swap(heap[poz*2],heap[poz]);
            poz<<=1;
        }
        else
        {
            swap(heap[poz*2+1],heap[poz]);
            poz<<=1;
            ++poz;
        }
    }
    if(poz*2==elemx && heap[poz]>heap[poz*2])
        swap(heap[poz],heap[poz*2]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i].tmp>>v[i].val;
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        if(i<=k)
        {
            s+=v[i].tmp;
            baga(v[i].tmp);
            mx=max(mx,v[i].val*1LL*s);
        }
        else if(v[i].tmp>heap[1])
        {
            s+=v[i].tmp;
            s-=heap[1];
            scoate();
            baga(v[i].tmp);
            mx=max(mx,v[i].val*1LL*s);
        }
    }
    cout<<mx;
    return 0;
}