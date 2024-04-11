#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const int mod=123457;
int heap[100005];
int elemx;
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
int fv1[100005],fv2[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long m,pz=1,k,add=1,i,j,cnt=0,cnti=0,s=0,n;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        --fv2[fv1[a]];
        ++fv1[a];
        ++fv2[fv1[a]];
        baga(fv1[a]);
        if(heap[1]==1 || heap[1]*1LL*fv2[heap[1]]==i-1 && fv2[1]==1 || (heap[1]-1)*1LL*fv2[heap[1]-1]==i-heap[1] && fv2[heap[1]]==1)
            pz=i;
    }
    cout<<pz;
    return 0;
}