#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct ura
{
    int a,b,fel,pz;
}v[1000006];
int a[500005],b[500005];
int aib[1000006];
int lsb (int x)
{
    return x&-x;
}
int query (int pz)
{
    int s=0;
    for(int i=pz;i>0;i-=lsb(i))
        s+=aib[i];
    return s;
}
void update (int pz,int val)
{
    for(int i=pz;i<=1000000;i+=lsb(i))
        aib[i]+=val;
}
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int t[500005],poz[500005],q[1000006];
int tata (int pz)
{
    if(t[pz]==0)
        return pz;
    return t[pz]=tata(t[pz]);
}
int unite (int a, int b)
{
    if(tata(a)!=tata(b))
        t[tata(a)]=tata(b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,i,j,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        v[i].a=a[i];
        v[i].b=b[i];
        v[i].fel=1;
        v[i].pz=i;
        v[i+n].a=b[i];
        v[i+n].b=a[i];
        v[i+n].fel=2;
        v[i+n].pz=i;
    }
    sort(v+1,v+2*n+1,cmp);
    for(i=1;i<=2*n;++i)
    {
        if(v[i].fel==1)
        {
            s+=query(v[i].b);
            update(v[i].b,1);
        }
        else
        {
            swap(v[i].a,v[i].b);
            update(v[i].b,-1);
        }
        if(s>=n)
            break;
    }
    if(s!=n-1)
    {
        cout<<"NO";
        return 0;
    }
    int k=0;
    for(i=1;i<=2*n;++i)
    {
        if(v[i].fel==1)
        {
            q[++k]=v[i].pz;
            poz[v[i].pz]=k;
        }
        else
        {
            for(j=poz[v[i].pz]+1;j<=k;++j)
            {
                unite(v[i].pz,q[j]);
                --poz[q[j]];
                q[j-1]=q[j];
            }
            --k;
        }
    }
    s=0;
    for(i=1;i<=n;++i)
        if(t[i]==0)
            ++s;
    if(s>1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}