#include <bits/stdc++.h>

using namespace std;
struct ura
{
    int a,n1;
}fv[200005];
bool cmp (ura a, ura b)
{
    return a.a>b.a;
}
int heap[100003],elemx=0;
void baga(long long val)
{
    heap[++elemx]=val;
    long long poz=elemx;
    while(poz>1 && heap[poz]>heap[poz/2])
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
    while(poz*2+1<=elemx && heap[poz]<max(heap[poz*2],heap[poz*2+1]))
    {
        if(heap[poz*2]>heap[poz*2+1])
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
    if(poz*2==elemx && heap[poz]<heap[poz*2])
        swap(heap[poz],heap[poz*2]);
}
int mrc[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>a>>b;
            ++fv[a].a;
            fv[a].n1+=b;
        }
        sort(fv+1,fv+n+1,cmp);
        int pr=99999999;
        s=0;
        for(i=1;i<=n;++i)
        {
            mrc[i]=max(min(fv[i].a,pr-1),0);
            s+=mrc[i];
            pr=mrc[i];
        }
        cout<<s<<' ';
        i=1;
        j=1;
        int nr1=0;
        for(i=1;i<=n;++i)
        {
            while(j<=n && fv[j].a>=mrc[i])
            {
                baga(fv[j].n1);
                ++j;
            }
            nr1+=min(heap[1],mrc[i]);
            scoate();
        }
        cout<<nr1<<'\n';
        for(i=1;i<=n;++i)
            fv[i].a=fv[i].n1=0;
    }
    return 0;
}