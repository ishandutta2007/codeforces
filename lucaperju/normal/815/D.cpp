#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b,c;
}v[500005];
bool cmpa (ura a, ura b)
{
    return a.a<b.a;
}
bool cmpb (ura a, ura b)
{
    if(a.b<b.b)
        return true;
    if(a.b>b.b)
        return false;
    return a.c<b.c;
}
int h[500005],pz[500005];
int l,r;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n,a,b,c;
    cin>>n>>a>>b>>c;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a>>v[i].b>>v[i].c;
        v[i].a=a-v[i].a+1;
        v[i].b=b-v[i].b+1;
        v[i].c=c-v[i].c+1;
    }
    long long s=0;
    sort(v+1,v+n+1,cmpb);
    l=1;
    r=0;
    int mx=c;
    int lst=1;
    for(i=1;i<=n;++i)
    {
        if(v[i].c-1<mx)
        {
            if(lst<=v[i].b-1)
            {
                h[++r]=mx;
                pz[r]=v[i].b-1;
                lst=v[i].b;
            }
            mx=min(mx,v[i].c-1);
        }
    }
    h[++r]=mx;
    pz[r]=b;
    long long sc=0;
    for(i=l;i<=r;++i)
        sc=sc+h[i]*1LL*(pz[i]-pz[i-1]);
    sort(v+1,v+n+1,cmpa);
    j=1;
    for(i=1;i<=a;++i)
    {
        while(j<=n && v[j].a==i)
        {
            int bc=v[j].b,cc=v[j].c;
            while(h[l]>=cc)
            {
                if(l+1<=r && h[l+1]>=cc)
                {
                    sc=sc-(h[l]-h[l+1])*1LL*pz[l];
                    ++l;
                    continue;
                }
                else
                {
                    sc=sc-(h[l]-cc+1)*1LL*pz[l];
                    h[l]=cc-1;
                    break;
                }
            }
            while(pz[r]>=bc)
            {
                if(l<=r-1 && pz[r-1]>=bc)
                {
                    sc=sc-h[r]*1LL*(pz[r]-pz[r-1]);
                    --r;
                    continue;
                }
                else
                {
                    sc=sc-h[r]*1LL*(pz[r]-bc+1);
                    pz[r]=bc-1;
                    break;
                }
            }
            ++j;
        }
        s=s+sc;
    }
    cout<<s;
    return 0;
}