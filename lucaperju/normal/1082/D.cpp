

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int lgput (long long a, long long exp, long long mod)
{
    long long rez=1;
    while(exp)
        if(exp&1)rez*=a,rez%=mod,--exp;
            else a*=a,a%=mod,exp>>=1;
    rez%=mod;
    return rez;
}

struct ura
{
 int a,b,c;
}v[505];
bool cmp (ura a, ura b)
{
    return (a.a<b.a);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long i,j,cnt0=0,rezt=0,n,m,spatiu=0,poz=-1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a;
        v[i].c=v[i].a;
        v[i].b=i;
    }
    sort(v+1,v+n+1,cmp);
    reverse(v+1,v+n+1);
    for(i=1;i<=n;++i)
    {
        if(v[i].a>1)
            ++cnt0,spatiu+=v[i].a;
        else
            ++rezt;
    }
    if(cnt0==0)
    {
        cout<<"NO";
        return 0;
    }
    spatiu-=2*(cnt0-1);
    if(spatiu<rezt)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES "<<cnt0-1+(rezt>=1)+(rezt>=2)<<'\n';
    cout<<n-1<<'\n';
    j=1;
    for(i=2;i<=n;++i)
    {
        if(v[i].a>1)
        {
            cout<<v[i].b<<' '<<v[i-1].b<<'\n';
            --v[i].c;
            --v[i-1].c;
        }
        else if(i!=n || rezt==1)
        {
            if(poz==-1)
                poz=i;
            while(v[j].c<=0)
                ++j;
            cout<<v[i].b<<' '<<v[j].b<<'\n';
            --v[j].c;
        }
        else
            cout<<v[i].b<<' '<<v[poz-1].b<<'\n';
    }
}