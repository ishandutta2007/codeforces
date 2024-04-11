#include <bits/stdc++.h>

using namespace std;
int aib[200005];
int ocup[200005];
struct ura
{
    int av,bv,a,b;
}v[200005];
bool cmp1 (ura a, ura b)
{
    return a.av<b.av;
}
bool cmp2 (ura a, ura b)
{
    return a.bv<b.bv;
}
bool cmp3 (ura a, ura b)
{
    if(a.a>b.a)
        return true;
    if(a.a<b.a)
        return false;
    return a.b<b.b;
}
int lsb (int x)
{
    return x&-x;
}
void baga (int pz)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        ++aib[i];
}
int cat (int pz)
{
    long long s=0;
    for(int i=pz;i>0;i-=lsb(i))
        s+=aib[i];
    return s;
}
int main()
{
    long long n,m,i,j,a,b,c,cnt=0,k,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i].bv>>v[i].av;
    sort(v+1,v+n+1,cmp1);
    k=0;
    for(i=1;i<=n;++i)
    {
        if(v[i].av!=v[i-1].av)
            ++k;
        v[i].a=k;
    }
    sort(v+1,v+n+1,cmp2);
    k=0;
    for(i=1;i<=n;++i)
    {
        if(v[i].bv!=v[i-1].bv)
            ++k;
        v[i].b=k;
    }
    sort(v+1,v+n+1,cmp3);
    for(i=1;i<=n;)
    {
        for(j=i;v[j].a==v[i].a && j<=n;++j)
        {
            if(!ocup[v[j].b])
            {
                baga(v[j].b);
                ocup[v[j].b]=1;
            }
        }
        long long sc=cat(v[i].b);
        sc=sc*1LL*(cat(200000)-cat(v[i].b-1));
        s+=sc;
        for(j=i+1;v[j].a==v[i].a && j<=n;++j)
            s=s+(cat(200000)-cat(v[j].b-1))*1LL*(cat(v[j].b)-cat(v[j-1].b));
        i=j;
    }
    cout<<s;
    return 0;
}